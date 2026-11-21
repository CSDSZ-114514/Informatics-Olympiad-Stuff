#include<bits/stdc++.h>
using namespace std;
long long n,m,d[10005],s,t;
struct ED{
    long long u,v,w;
};
long long dx[4]={0,0,1,-1};
long long dy[4]={1,-1,0,0};
vector<ED> e;
vector<long long> h[10005];
void add_edge(long long a,long long b,long long c){
    e.push_back({a,b,c});
    h[a].push_back(e.size()-1);
    e.push_back({b,a,0});
    h[b].push_back(e.size()-1);
}
long long toto1(long long x,long long y){
    return (x-1)*m+y;
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
    s=0,t=n*m+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            long long s;
            cin>>s;
            if(s==1){
                add_edge(0,toto1(i,j),1e9);
            }else if(s==2){
                add_edge(toto1(i,j),n*m+1,1e9);
            }
            for(int k=0;k<4;k++){
                long long tx=i+dx[k];
                long long ty=j+dy[k];
                if(tx<1||ty<1||tx>n||ty>m)continue;
                add_edge(toto1(i,j),toto1(tx,ty),1);
            }
        }
    }
    long long flow=0;
    while(bfs()){
		flow+=dfs(s,1e9);
	}
    cout<<flow;
    return 0;

}