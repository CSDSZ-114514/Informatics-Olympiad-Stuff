#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,pre[100005],mf[100005];
struct ED{
    long long u,v,w;
};
vector<ED> e;
vector<long long> he[100005];
bool bfs(){
    memset(mf,0,sizeof(mf));
    mf[1]=1e9;
    queue<long long> q;
    q.push(1);
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        if(u==m){
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
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long s,t,c;cin>>s>>t>>c;
        e.push_back({s,t,c});
        he[s].push_back(e.size()-1);
        e.push_back({t,s,0});
        he[t].push_back(e.size()-1);
    }
    while(bfs()){
        long long v=m;
        while(v!=1){
            long long i=pre[v];
            e[i].w-=mf[m];
            e[i^1].w+=mf[m];
            v=e[i].u;
        }
        ans+=mf[m];
    }
    cout<<ans;
    return 0;
}