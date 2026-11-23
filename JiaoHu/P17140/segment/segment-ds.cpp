#include "segment.h"
#include <bits/stdc++.h>
using namespace std;

static const int MOD = 998244353;
static const int MAXR = 1005;
static const int MAXN = 3005;

/*
 *  一棵树 <=> 交图连通 且 无环。区间图是弦图，所以“无环” <=> “无三角形”
 *  <=> 没有任何一个点被 3 条线段覆盖；同时“连通” <=> 并集是一整段。
 *
 *  DP：把选中的线段按左端点从小到大加入，记录最大的两个右端点
 *  (j = 最大, p = 次大)。新线段 [l, r] 能加入当且仅当 p < l <= j，
 *  加入后状态变成 (max(j,r), min(j,r))（它恰好只和实现 j 的那条相交）。
 *  当大小 >= 2 时恒有 p >= 已选线段的所有左端点，所以加入顺序被自动强制，
 *  每个集合恰好被算一次。
 *
 *  pre[a][t] = sum_{p <= t} dp[rv[a]][p]         （对第二维做前缀和）
 *  raw(a,b), b < a = sum_{seg r=rv[a], l<=rv[b]} pre[b][bucket(l)]   （新的是最大右端点）
 *                  + sum_{seg r=rv[b]}           pre[a][bucket(l)]   （r 不超过旧最大值）
 *  raw(a,a)        = sum_{seg r=rv[a]}           pre[a][bucket(l)]
 *  大小为 2 的一层直接构造：单条线段的状态里没有它的左端点，无法用上式转移。
 *
 *  令 R = 不同右端点个数 (<= 1000)，每层 O(R^2 + sum(r_i-l_i) + sum(m-r_i+1))，
 *  总复杂度 O((R^2 + nm) K)，且只保留前缀和数组、常数极小。
 */

static int PA[MAXR][MAXR], PB[MAXR][MAXR];
static int rv[MAXR];     // 不同的右端点，升序
static int cntR[MAXR];   // 右端点为 rv[a] 的线段条数
static int rawCnt[MAXN]; // 右端点恰好为 t 的线段条数（未离散化）
static int idxOf[MAXN];  // 右端点取值对应的离散化下标
static int lst[MAXN];    // 左端点，按右端点分组，组内升序
static int lstBi[MAXN];  // bucket(l) = 不大于 l-1 的不同右端点个数
static int segSt[MAXR], segEn[MAXR];

void init(int c, int t) {
    (void)c;
    (void)t;
}

vector<int> segment(int n, int m, int k, vector<int> lv, vector<int> rvIn) {
    vector<int> res(k + 1, 0);
    if (k >= 1) res[1] = n;
    if (n == 0 || k <= 1) return res;

    static int ord[MAXN];
    for (int i = 0; i < n; i++) ord[i] = i;
    sort(ord, ord + n, [&](int x, int y) {
        if (rvIn[x] != rvIn[y]) return rvIn[x] < rvIn[y];
        return lv[x] < lv[y];
    });

    int R = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || rvIn[ord[i]] != rvIn[ord[i - 1]]) {
            rv[R] = rvIn[ord[i]];
            cntR[R] = 0;
            ++R;
        }
        ++cntR[R - 1];
    }
    for (int a = 0, i = 0; a < R; a++) {
        segSt[a] = i;
        idxOf[rv[a]] = a;
        for (int c = 0; c < cntR[a]; c++, i++) {
            int l = lv[ord[i]];
            lst[i] = l;
            lstBi[i] = (int)(upper_bound(rv, rv + R, l - 1) - rv);
        }
        segEn[a] = i;
    }
    for (int i = 0; i <= m; i++) rawCnt[i] = 0;
    for (int i = 0; i < n; i++) rawCnt[rvIn[i]]++;

    int(*P)[MAXR] = PA;
    int(*Q)[MAXR] = PB;

    // ---- 大小 2 --------------------------------------------------------
    // 无序相交线段对，格子 = (较大右端点, 较小右端点)
    for (int a = 0; a < R; a++) {
        for (int c = 0; c <= a + 1; c++) P[a][c] = 0;
    }
    for (int a = 0; a < R; a++) {
        // 右端点相同的两条一定相交
        P[a][a + 1] = (int)((long long)cntR[a] * (cntR[a] - 1) / 2);
        for (int t = segSt[a]; t < segEn[a]; t++) {
            const int l = lst[t], rr = rv[a];
            for (int v = l; v < rr; v++) {
                if (!rawCnt[v]) continue;
                P[a][idxOf[v] + 1] += rawCnt[v];
            }
        }
    }
    // 把 dp 行原地变成前缀和（P[a][b+1] 此刻存的是 dp[a][b]）
    for (int a = 0; a < R; a++) {
        int acc = 0;
        for (int b = 0; b <= a; b++) {
            acc += P[a][b + 1];
            if (acc >= MOD) acc -= MOD;
            P[a][b + 1] = acc;
        }
        P[a][0] = 0;
    }
    {
        long long tot = 0;
        for (int a = 0; a < R; a++) tot += P[a][a + 1];
        res[2] = (int)(tot % MOD);
    }

    // ---- 大小 3..k -----------------------------------------------------
    for (int s = 3; s <= k; s++) {
        long long tot = 0;
        for (int a = 0; a < R; a++) {
            const int *rowA = P[a];
            int *out = Q[a];
            int acc = 0;
            out[0] = 0;
            const int sa = segSt[a], ea = segEn[a];
            for (int b = 0; b <= a; b++) {
                int val = 0;
                if (b < a) {
                    const int *rowB = P[b];
                    const int pv = rv[b];
                    for (int t = sa; t < ea; t++) {
                        if (lst[t] > pv) break;
                        int x = val + rowB[lstBi[t]];
                        val = x - (x >= MOD ? MOD : 0);
                    }
                }
                for (int t = segSt[b]; t < segEn[b]; t++) {
                    int x = val + rowA[lstBi[t]];
                    val = x - (x >= MOD ? MOD : 0);
                }
                int x = acc + val;
                acc = x - (x >= MOD ? MOD : 0);
                out[b + 1] = acc;
                tot += val;
            }
        }
        res[s] = (int)(tot % MOD);
        if (tot == 0) break; // 这一层没有方案，更大的也一定没有
        swap(P, Q);
    }
    return res;
}
