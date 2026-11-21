#include <bits/stdc++.h>
using namespace std;
long long n, m, s;
vector<long long> ed[800005];
long long dfn[500005], jmp[500005][25];
void dfs(long long u,long long fa){
    dfn[u]=dfn[fa]+1;
    jmp[u][0] = fa;
    for (int i = 1; i <= 20;i++){
        jmp[u][i] = jmp[jmp[u][i - 1]][i - 1];
    }
    for(auto t:ed[u]){
        if(t==fa)
            continue;
        dfs(t, u);
    }
    return;
}
long long lca(long long u,long long v){
    if(dfn[u]<dfn[v])
        swap(u, v);
    for (int i = 20; i >= 0;i--){
        if(dfn[jmp[u][i]]>=dfn[v]){
            u = jmp[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for (int i = 20; i >= 0;i--){
        if(jmp[u][i]!=jmp[v][i]){
            u = jmp[u][i];
            v = jmp[v][i];
        }
    }
    return jmp[u][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        ed[x].push_back(y);
        ed[y].push_back(x);
    }
    dfs(s, 0);
    for (int i = 1; i <= m;i++){
        long long a, b;
        cin >> a >> b;
        cout << lca(a, b)<<'\n';
    }

        return 0;
}