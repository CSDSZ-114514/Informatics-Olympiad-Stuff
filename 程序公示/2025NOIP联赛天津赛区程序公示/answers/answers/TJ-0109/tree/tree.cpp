#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}

int t, n, m, a[8005], sz[8005];
int dp[365][365][365];
vector<int>s[8005];

void dfs(int x) {
    dp[x][1][0] = 0, sz[x] = 1;
    for(auto i : s[x]) {
        dfs(i);
        sz[x] += sz[i];
    }
    int szn = 1;
    for(auto i : s[x]) {
        for(int j = szn; j >= 0; j--) {
            for(int px = sz[x]; px >= 0; px--) {
                for(int k = sz[i]; k >= 0; k--) {
                    for(int o = sz[i]; o >= 0; o--) {
                        dp[x][j + k][max(px, o)] = max(dp[x][j + k][max(px, o)], dp[x][j][px] + dp[i][k][o]);
                        if(o <= px)break;
                    }
                }
            }
        }
        szn += sz[i];
    }
    for(int i = 0; i <= sz[x]; i++) {
        for(int j = 0; j <= sz[x]; j++) {
            dp[x][i][j] += j;
        }
    }
    for(int i = sz[x]; i >= 1; i--) {
        for(int j = 0; j <= sz[x]; j++) {
            dp[x][i - 1][j + 1] = max(dp[x][i - 1][j + 1], dp[x][i][j] + 1);
        }
    }
}

int main() {
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    cin >> t;
    for(int ii = 1; ii <= t; ii++) {
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)s[i].clear();
        for(int i = 2; i <= n; i++)scanf("%d", &a[i]), s[a[i]].push_back(i);
        for(int i = 0;i<=n;i++){
            for(int j = 0;j<=n;j++){
                for(int k = 0;k<=n;k++){
                    dp[i][j][k] = -1e9;
                }
            }
        }
        dfs(1);
        int ans = 0;
        for(int i = 0;i<=n;i++)ans = max(ans, dp[1][0][i]);
        printf("%d\n", ans);
    }
    return 0;
}
/*

*/

