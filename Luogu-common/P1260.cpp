#include<bits/stdc++.h>
using namespace std;
long long d[10005],n,m,cnt[10005];bool vis[10005];
struct node{
	long long v,w;
};queue<int> q;
vector<node> ed[10005];
bool spfa(int s) {
	for(int i=1; i<=n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0;
	vis[s] = 1;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();		
		vis[u] = 0;
		for(node t: ed[u]) {
			if(d[t.v] > d[u] + t.w) {
				d[t.v] = d[u] + t.w;
				if(!vis[t.v]) {
					vis[t.v] = 1;
					q.push(t.v);
				} 
				cnt[t.v] = cnt[u] + 1; 
				if(cnt[t.v] > n) {
					return false;
				}
			}
		}
	}
	
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int ti,tj,b;
		cin>>ti>>tj>>b;
		ed[tj].push_back({ti,b}); 	
	}
	for(int i=1; i<=n; i++) {
		ed[0].push_back({i, 0});
	}
	if(spfa(0)) {
		long long dx=1e9;
		for(int i=1;i<=n;i++){
			dx=min(dx,d[i]);
		}
		for(int i=1; i<=n; i++) {
			cout<<d[i]-dx<<endl; 
		}
	} else {
		cout<<"NO SOLUTION";
	}
	return 0;
}
