#include<bits/stdc++.h>
using namespace std;
long long n,k,m,s;
long long c[100005],ant[505][505];
struct node{
	long long v,w;
};
vector<node> ed[100005];
queue<int> q;
long long d[100005],pre[100005];
bool vis[100005];
bool check(long long u,long long v){
	while(u!=0){
		if(ant[c[v]][c[u]]==1 ||c[u]==c[v]){
			return false;
		}
		u=pre[u];
	}
	return true;
}
void spfa(long long s){
	q.push(s);
	for(int i=1;i<=n;i++){
		d[i]=1e9;
	}
	vis[s]=1;
	d[s]=0;
	while(!q.empty()){
		long long u=q.front();
		q.pop();
		vis[u]=0;
		for(node t:ed[u]){
			if((d[t.v]>d[u]+t.w)&&check(u,t.v)){
				d[t.v]=d[u]+t.w;
				pre[t.v]=u;
				if(vis[t.v]==0){
					q.push(t.v);
					vis[t.v]=1;
				}
			}
		}
	}
}
long long t;
int main(){
	cin>>n>>k>>m>>s>>t;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=k;i++){
		for(int j=1;j<=k;j++){
			cin>>ant[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		long long u,v,d;
		cin>>u>>v>>d;
		ed[u].push_back({v,d});
		ed[v].push_back({u,d});
	}
	spfa(s);
	if(d[t]!=1e9){
		cout<<d[t];
	}else{
		cout<<-1;
	}
}
