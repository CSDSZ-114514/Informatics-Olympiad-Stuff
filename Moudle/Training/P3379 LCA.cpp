#include<bits/stdc++.h>
using namespace std;
long long n, m, s;
vector<long long> e[1000005];
long long dep[10000005],f[1000005][25];
void dfs(long long u,long long fa){
    dep[u]=dep[fa]+1;
    f[u][0] = fa;
    for (int i = 1; i <= 20;i++){
        f[u][i] = f[f[u][i - 1]][i - 1];
    }
    for(auto t:e[u]){
        if(t!=fa){
            dfs(t, u);
        }
    }
}
long long lca(long long u,long long v){
    if(dep[u]<dep[v]){
        swap(u, v);
    }
    for (int i = 20; i >= 0;i--){
        if(dep[f[u][i]]>=dep[v]){
            u = f[u][i];
        }
    }
    if(u==v){
        return u;
    }else{
        for (int i = 20; i >= 0;i--){
            if(f[u][i]!=f[v][i]){
                u = f[u][i];
                v = f[v][i];
            }
        }
    }
    return f[u][0];
}
int main(){
    cin.tie(0);
    
    cin >> n >> m >> s;
    for (int i = 1; i < n;i++){
        long long x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(s, 0);
    for (int i = 1; i <= m;i++){
        long long a, b;
        cin >> a >> b;
        cout << lca(a, b)<<endl;
    }
        return 0;
}