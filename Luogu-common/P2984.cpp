#include <bits/stdc++.h>
using namespace std;
long long B,n,m;
struct node{
	long long v,w;
};vector<node> ed[100005];
queue<int> q;long long d[50005];bool vis[500005];
void spfa(long long s){
	q.push(s);
	for(int i=1;i<=n;i++){
		d[i]=1e9;
	}
	vis[s]=1;
	d[s]=0;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(node t:ed[u]){
			if(d[t.v]>d[u]+t.w){
				d[t.v]=d[u]+t.w;
				if(vis[t.v]==0){
					q.push(t.v);
					vis[t.v]=1;
				}
			}
		}
	}
	
}
int main(){
	cin>>n>>m>>B;
	for(int i=1;i<=m;i++){
		long long r,s,l;
		cin>>r>>s>>l;
		ed[r].push_back({s,l});
		ed[s].push_back({r,l});
	}
	spfa(1);
	while(B--){
		long long p,q;
		cin>>p>>q;
		cout<<d[p]+d[q]<<endl;
	}
	
}
