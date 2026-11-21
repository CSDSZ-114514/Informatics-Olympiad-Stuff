#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 8010;
int sta[maxn] = {0};
vector <int > G[maxn];
ll res = 0, num = 0;
int nn[maxn] = {0};
void dfs(int u) {
    // printf("%d\n", u);
    for (int i = 0; i < G[u].size(); i ++) {
        int v = G[u][i];
        dfs(v);
        nn[u] |= nn[v];
    }
    for (int i = 0; i <= 20; i ++) {
        if (((nn[u] >> i) & 1) == 0) {
            num += i;
            break;
        }
    }
}
void mksearch(int now, int n) {
    if (now == n + 1) {
        num = 0;
        for (int i = 1; i <= n; i ++) {
            nn[i] = sta[i];
        }
        dfs(1);
        if (num > res) {
            res = num;
            // for (int i = 1; i <= n; i ++) {
            //     printf("%d ", nn[i]);
            // }
            // printf("\n");
        }
        return;
    }
    for (int i = 0; i < n; i ++) {
        sta[now] = (1 << i);
        mksearch(now + 1, n);
    }
}
int main () {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int _;
    scanf("%d", &_);
    while(_ --) {
        int n, m;
        scanf("%d%d", &n, &m);
        res = 0;
        for (int i = 1; i <= n; i ++) {
            G[i].clear();
        }
        for (int i = 2; i <= n; i ++) {
            int p;
            scanf("%d", &p);
            G[p].push_back(i);
        }
        mksearch(1, n);
        printf("%lld\n", res);
    }
    return 0;
}