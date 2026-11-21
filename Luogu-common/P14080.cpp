#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct EDGE {
    long long v, w, id;
};
struct EDGE2 {
    long long u, v, w,id;
} a[100005];
long long d[100005],res[100005];
bool vis[100005], flag[100005];
vector<EDGE> e[100005];
long long fa[100005], ans[100005];
long long find(long long x) {
    if (x == fa[x]) {
        return x;
    } else {
        return fa[x] = find(fa[x]);
    }
}
bool cmp(EDGE2 x, EDGE2 y) { return x.w < y.w; }
long long kruskal() {
    // 并查集初始化
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    // 所有节点按权重从小到大排序
    sort(a + 1, a + m + 1, cmp);

    long long sum = 0;
    for (int i = 1; i <= m; i++) { // 依次处理m条边
        long long x = find(a[i].u);      // 并查集查询当前边两个节点所在集合的根节点
        long long y = find(a[i].v);
        if (x != y) {      // 判断当前边得两个节点是否在同一集合，如果不是
            sum += a[i].w; // 选用当前边
            e[a[i].u].push_back({a[i].v, a[i].w, a[i].id});
            flag[a[i].id] = true;
            e[a[i].v].push_back({a[i].u, a[i].w, a[i].id});
            fa[x] = y; // 将两个集合合并
        }
    }
    return sum;
}
long long f[100005], num[100005], dep[100005];
void dfs(long long u, long long fa) {
    f[u] = fa;
    dep[u] = dep[fa] + 1;
    for (auto t : e[u]) {
        if (t.v == fa)
            continue;
        num[t.v] = t.id;
        dfs(t.v, u);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        a[i].u = u;
        a[i].v = v;
        a[i].w = w;
        a[i].id = i;
    }
    long long sum=kruskal();
    dfs(1, 1);
    for (int i = 1; i <= m; i++) {
        ans[i] = 1e18;
    }
    for (int i = 1; i <= m; i++) {
        if (flag[a[i].id] == 0) {
            long long u = a[i].u, v = a[i].v;
            while (u != v) {
                if (dep[u] < dep[v]) {
                    swap(u, v);
                }
                ans[num[u]] = min(ans[num[u]], a[i].w);
                u = f[u];
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        if(flag[a[i].id]) {
            if(ans[a[i].id] == 1e18) {
                res[a[i].id] = -1;
            } else {
                res[a[i].id] = sum - a[i].w + ans[a[i].id];
            }
            
        } else {
            res[a[i].id] = sum;
        }
    }
    for (int i = 1; i <= m;i++){
        // if (res[i] == 1e18){
        //     cout << -1 << endl;
        // }else{
            cout << res[i] << endl;
        // }
    }
        return 0;
}