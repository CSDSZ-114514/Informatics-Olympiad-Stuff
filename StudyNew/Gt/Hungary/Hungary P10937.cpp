#include<bits/stdc++.h>
using namespace std;
long long n,m,t,e,ans;
bool tp[10005][10005];
bool vis[1000005];
long long match[1000005];
vector<long long> ed[1000005];
bool hungary(long long u){
    for(long long t:ed[u]){
        if(vis[t])continue;
        vis[t]=1;
        if(!match[t]||hungary(match[t])){
            match[t]=u;
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n>>m>>t;
    memset(tp,0,sizeof(tp));
    for(int i=1;i<=t;i++){
        long long x,y;cin>>x>>y;
        tp[x][y]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(!tp[i][j]){
                ed[i].push_back(j);
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(hungary(i)){
            ans++;
        }
    } 
    cout<<ans<<endl;
   
    return 0;
}