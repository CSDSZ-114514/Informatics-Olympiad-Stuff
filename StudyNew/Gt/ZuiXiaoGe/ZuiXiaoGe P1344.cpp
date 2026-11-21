#include<bits/stdc++.h>
using namespace std;
long long n,m,d[205];
struct ED{
    long long u,v,w;
};
vector<ED> e;
vector<long long> h[205];
void add_edge(long long a,long long b,long long c){
    e.push_back({a,b,c});
    h[a].push_back(e.size()-1);
    e.push_back({b,a,0});
    h[b].push_back(e.size()-1);
}
bool bfs(){
    memset(d,0,sizeof(d));
    d[1]=1;
    queue<long long> q;
    q.push(1);
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        if(u==n)return true;
        for(long long i:h[u]){
            long long v=e[i].v;
            if(d[v]==0&&e[i].w>0){
                d[v]=d[u]+1;
                q.push(v);
            }
        }
    }
    return false;
}
long long dfs(long long u,long long mf){
    if(u==n)return mf;
    long long sum=0;
    for(long long i:h[u]){
        long long v=e[i].v;
        if(d[v]==d[u]+1&&e[i].w){
            long long f=dfs(v,min(mf,e[i].w));
            e[i].w-=f;
            e[i^1].w+=f;
            mf-=f;
            sum+=f;
            if(mf==0){
                break;
            }
        }
    }
    return sum;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        long long s,e,c;
        cin>>s>>e>>c;
        add_edge(s,e,c);
    }
    long long flow=0;
    while(bfs()){
        flow+=dfs(1,INT_MAX);
    }
    for(int i=0;i<m;i++){
        if(e[2*i].w==0){
            e[2*i].w=1;
            e[2*i+1].w=0;
        }else{
            e[2*i].w=INT_MAX;
            e[2*i+1].w=0;
        }
    }
    long long flow2=0;
    while(bfs()){
        flow2+=dfs(1,INT_MAX);
    }
    cout<<flow<<" "<<flow2;
    return 0;

}