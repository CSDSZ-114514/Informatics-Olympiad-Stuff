#include<bits/stdc++.h>
using namespace std;
long long n,m,e,ans;
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
    cin>>m>>n;
    while(true){
        long long u,v;
        cin>>u>>v;
        if(u==-1&&v==-1){
            break;
        }
        ed[v].push_back(u);
    }
    for(int i=m+1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(hungary(i)){
            ans++;
        }
    } 
    cout<<ans<<endl;
    for(int i=1;i<=m;i++){
        if(match[i]){
            cout<<i<<" "<<match[i]<<endl;
        }
    }
   
    return 0;
}