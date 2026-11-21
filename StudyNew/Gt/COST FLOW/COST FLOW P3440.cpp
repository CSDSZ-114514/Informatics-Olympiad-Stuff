#include<bits/stdc++.h>
using namespace std;
const int N=2e3;
int n,s,t,vis[N],pre[N];
long long ans,d[N],mf[N],g[N][N],sum[N];
struct node{
	int u,v;
	long long w,c;
};
vector<node> e;
vector<int> h[N];
void add(int u,int v,long long w,long long c){
	e.push_back({u,v,w,c});
	h[u].push_back(e.size()-1);
	e.push_back({v,u,0,-c});
	h[v].push_back(e.size()-1);
}
bool sf(){
	memset(d,0x3f,sizeof(d));
	memset(mf,0,sizeof(mf));
	d[s]=0;
	mf[s]=1e9;
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i:h[u]){
			int v=e[i].v;
			if(d[v]>d[u]+e[i].c&&e[i].w>0){
				d[v]=d[u]+e[i].c;
				mf[v]=min(mf[u],e[i].w);
				pre[v]=i;
				if(!vis[v]){
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	return mf[t]>0;
}
int main(){
    ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
    cin>>n;
	s=0,t=2*n+1;
    for(int i=1;i<=n;i++){
        long long m,a,b,k;
        cin>>m>>a>>b>>k;
        for(int j=a;j<=b;j++){
            add(m,j,1,k*abs(m-j));
        }
    }
    for(int i=1;i<=n;i++){
        add(s,i,1,0);
        add(i,t,1,0);
    }
    while(sf())
	{
		int v=t;
		while(v!=s){
			int i=pre[v];
			e[i].w-=mf[t];
			e[i^1].w+=mf[t];
			v=e[i].u;
		}
//		flow+=mf[t];
		ans+=mf[t]*d[t];
	}
    cout<<ans;
    
}