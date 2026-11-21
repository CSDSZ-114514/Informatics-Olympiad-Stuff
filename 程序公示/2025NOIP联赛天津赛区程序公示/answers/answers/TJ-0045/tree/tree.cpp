#include<bits/stdc++.h>

using namespace std;

const int N = 8e3 + 5;
int n, m, ans, maxdep;
int p[N], kids[N], sub[N], dp[N], w[N];
bool vis[N];
vector<int> g[N];
vector<int> st[N];

void dep(int u, int pa, int depth)
{
	//cout << u << "\n";
    if(kids[u] == 0)
    {
        maxdep = max(maxdep, depth);
        return;
    }
    dp[u] = depth;
    for(auto v : g[u])
    {
        if(v != pa) dep(v, u, depth + 1);
    }
}

void dfs(int u)
{
    vis[u] = true;
    if(dp[u] == maxdep - 1)
    {
        ans += kids[u] + 2;
        w[u] = kids[u] + 1;
        return;
    }
    else
    {
        if(dp[u] == maxdep) return;
        else
        {
            for(auto v : g[u])
            {
                if(vis[v]) continue;
                w[u] = max(w[u], w[v]) + 1;
            }
        }
    }
//    if(!kids[u])
//    {
//        if(!st[sub[u]].size())
//        {
//            st[sub[u]].push_back(0);
//            return;
//        }
//        else
//        {
//            st[sub[u]].push_back(st[sub[u]].back() + 1);
//            return;
//        }
//    }
//    for(auto v : g[u])
//    {
//        if(!vis[u])
//        {
//            dfs(v);
//            kids[u]--;
//        }
//    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tree.in", "r", stdin);
    freopen("tree.out", "w", stdout);
    int t;
    cin >> t;
    while(t--)
    {
        memset(p, 0, sizeof p);
        p[1] = 1;
        for(int i = 0; i < N; i++) g[i].clear();
        cin >> n >> m;
        for(int i = 2; i <= n; i++)
        {
            cin >> p[i];
            g[i].push_back(p[i]);
            g[p[i]].push_back(i);
            kids[i]++;
            sub[i] = p[i];
        }
//        for(int i = 1; i <= n; i++)
//        {
//            for(auto j : g[i]) cout << j << " ";
//            cout << "\n";
//        }
        dep(1, -1, 0);
        for(int i = 1; i <= n; i++) cout << dp[i] << " ";
        cout << "\n";
        dfs(1);
//        for(int i = 1; i <= n; i++)
//        {
//            if(st[i].size()) ans += st[i].back() + 1;
//        }
        cout << ans << "\n";
    }
}
