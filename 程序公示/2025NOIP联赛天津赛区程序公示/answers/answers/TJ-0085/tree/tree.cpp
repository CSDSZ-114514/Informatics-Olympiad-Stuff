#include <bits/stdc++.h>
#define maxn 200005
using namespace std;
int n,T,m;
int a1;
int e[maxn],ne[maxn],h[maxn],idx;
int ans;
typedef pair<int,int> pii;
void add(int a,int b){
	e[idx]=b;
	ne[idx]=h[a];
	h[a]=idx++;
}
int d[maxn];
int zs[maxn];
void dfs(int u,int fa,int dt){
	d[u]=dt;
//	cout<<u<<" "<<dt<<"\n";
	for(int i=h[u];i!=-1;i=ne[i]){
		int j=e[i];
		if(j==fa)continue;
		dfs(j,u,dt+1);
		zs[u]+=zs[j];
	}
}
int gx[maxn];
void dfs2(int u,int fa,int gx,int dt){
	priority_queue<pii,vector<pii> >q;
	for(int i=h[u];i!=-1;i=ne[i]){
		int j=e[i];
		if(j==fa)continue;
		if(u==1)ans--;
		q.push(make_pair(zs[j],j));
	}
	int flag=0;
	while(q.size()){
		int j=q.top().second;
		q.pop();
		if(!flag)dfs2(j,u,0,dt),flag=1;
		else dfs2(j,u,1,d[u]);
	}
//	if(u!=1){
//		if(!gx)ans++;
//		ans+=max(dt+1,d[u]-dt);
		if(dt==0){
			ans+=d[u]+1;
		}
		else{
			ans+=dt+1;
		}
//	}	
//	cout<<u<<" "<<gx<<" "<<dt<<" "<<d[u]<<" "<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++){
		memset(e,0,sizeof(e));
		memset(ne,0,sizeof(ne));
		idx=0;
		memset(h,-1,sizeof(h));
		memset(d,0,sizeof(d));
		memset(gx,0,sizeof(gx));
		ans=1;
		cin>>n>>m;
		for(int i=1;i<=n;i++)zs[i]=1;
		for(int i=2;i<=n;i++){
			cin>>a1;
			add(a1,i);
			add(i,a1);
		}
		dfs(1,0,0);
//		for(int i=0;i<=n;i++){
//			cout<<d[i]<<" ";
//		}
		dfs2(1,0,0,0);
		cout<<ans<<"\n";
	}
	return 0;
}
