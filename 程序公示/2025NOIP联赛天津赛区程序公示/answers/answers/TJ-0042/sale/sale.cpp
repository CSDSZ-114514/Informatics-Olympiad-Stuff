#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>
#define file_io(id) do { \
    freopen(id".in", "r", stdin); freopen(id".out", "w", stdout); \
} while(false)
using namespace std;

struct candy {
    int a, r, id, w;
};

const int MOD = 998244353;
const int MAXN = 5e3 + 10;
int c, t;
int n, m;
int ans, mx = -0x3f3f3f3f;
candy cd[MAXN];

void dfs(int dep) {
    if (dep == n + 1) {
        int cost = 0, money = m;
        candy cd_tmp[MAXN];
        copy(cd + 1, cd + n + 1, cd_tmp + 1);
        sort(cd_tmp + 1, cd_tmp + n + 1, [](candy x, candy y) {
             if (x.r > y.r) return true;
             else if (x.r < y.r) return false;
             else if (x.a > y.a) return true;
             else if (x.a < y.a) return false;
             else return x.id < y.id;
        });
        for (int i = 1; i <= n; i++) {
            if (money >= cd_tmp[i].w)
                cost += cd_tmp[i].a, money -= cd_tmp[i].w;
        }
        if (cost > mx) ans = 1, mx = cost;
        else if (cost == mx) ans++;
        return;
    }

    for (int w : {1, 2}) {
        //cout << dep << " " << w << endl;
        cd[dep].r = cd[dep].a * 2 / w, cd[dep].w = w;
        dfs(dep + 1);
    }
}

int main() {
    file_io("sale");
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> c >> t;
    while (t--) {
        ans = 0, mx = -0x3f3f3f3f;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> cd[i].a, cd[i].id = i;
        dfs(1);
        cout << pow(2, n) - ans << endl;
    }
    return 0;
}
