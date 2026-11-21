#include<bits/stdc++.h>
using namespace std;
long long n,m,d[405],s,t;
struct ED{
    long long u,v,w;
};
vector<ED> e;
vector<long long> h[405];
void add_edge(long long a,long long b,long long c){
    e.push_back({a,b,c});
    h[a].push_back(e.size()-1);
    e.push_back({b,a,0});
    h[b].push_back(e.size()-1);
}
bool bfs(){
    memset(d,0,sizeof(d));
    d[s]=1;
    queue<long long> q;
    q.push(s);
    while(!q.empty()){
        long long u=q.front();
        q.pop();
        if(u==t)return true;
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
    if(u==t)return mf;
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
    s=0,t=n+1;
    for(long long i=1;i<=n;i++){
        long long k;cin>>k;
        if(k==1){
            add_edge(s,i,1);
        }else{
            add_edge(i,t,1);
        }
    }
    for(long long i=1;i<=m;i++){
        long long a=0,b=0;
        cin>>a>>b;
        add_edge(a,b,1);
        add_edge(b,a,1);
    }
    long long flow=0;
    while(bfs()){
		flow+=dfs(s,1e9);
	}
    cout<<flow;
    return 0;

}