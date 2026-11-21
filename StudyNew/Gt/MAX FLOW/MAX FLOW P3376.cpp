#include<bits/stdc++.h>
using namespace std;
long long n,m,s,t;
long long ans;
struct ED{
    long long u,v,w;
};
struct
vector<ED> e;
vector<long long> he[100005];
long long mf[100005],pre[100005];
bool bfs(){
    memset(mf,0,sizeof(mf));
    mf[s]=1e9;
    queue<long long> q;
    q.push(s);
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        if(u==t){
            return true;
        }
        for(long long i:he[u]){
            long long v=e[i].v;
            if(mf[v]==0&&e[i].w>0){
                mf[v]=min(mf[u],e[i].w);
                pre[v]=i;
                q.push(v);
            }
        }
    }
    return false;
}
int main(){
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++){
        long long u,v,w;
        cin>>u>>v>>w;
        e.push_back({u,v,w});
        he[u].push_back(e.size()-1);
        e.push_back({v,u,0});
        he[v].push_back(e.size()-1);
    }
    while(bfs()){
        long long v=t;
        while(v!=s){
            long long i=pre[v];
            e[i].w-=mf[t];
            e[i^1].w+=mf[t];
            v=e[i].u;
        }
        ans+=mf[t];
    }
    cout<<ans;
    return 0;
}