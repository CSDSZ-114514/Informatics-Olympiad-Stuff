#include<bits/stdc++.h>
using namespace std;
struct ED{
    long long v,w;
};
int n, x, ans, idx, t[3100000][2];
vector<ED> e[3100000];
bool vis[3100000];
long long yhz[3100000];
void dfs(long long u,long long p){
    for(ED t:e[u]){
        if(t.v!=p){
            yhz[t.v]=yhz[u]^t.w;
            dfs(t.v,u);
            //insert(yhz[t]);
        }
    }
}
void insert(int x) {
    long long p=0;
    for(int i=30;i>=0;i--){
        long long j=(x>>i)&1;
        if(t[p][j]==0){
            t[p][j]=++idx;
        }
        p=t[p][j];
    }
}
int query(int x) {
    int p=0,res=0;
    for(int i=30;i>=0;i--){
        long long j=(x>>i)&1;
        res*=2;
        if(t[p][!j]!=0){
            res|=1;
            p=t[p][!j];
        }else{
            p=t[p][j];
        }
    }
    return res;
}
int main(){
    long long n;cin>>n;
    for(int i=1;i<=n-1;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    dfs(1,1);
    
    for(int i=1;i<=n; i++) {
        ans = max(ans, query(yhz[i])); 
        insert(yhz[i]);  
    }
    
    cout << ans << endl;
    return 0;
}