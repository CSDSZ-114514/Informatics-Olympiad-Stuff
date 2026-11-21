#include<bits/stdc++.h>
using namespace std;
long long n,k;
struct ED{
	long long w,v;
};
vector<ED> e[1000005];
long long d[1000005],inf=1e18;
queue<long long> q;
bool vis[1000005]; 
void spfa(int s) {
	for(int i=1; i<=n; i++) {
		d[i] = inf;
	}
	d[s] = 1; 
	q.push(s);
	vis[s] = 1;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0; 
		
		for(ED t:e[u]) {
			if(d[t.v] > d[u] + t.w) { 
				d[t.v] = d[u] + t.w;
				if(!vis[t.v]) { 
					q.push(t.v); 
					vis[t.v] = 1; 
				}
			}
		}
	}
} 
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		long long a,b;
		cin>>a>>b;
		e[a].push_back({1,b}); 
	}
	spfa(1);
	if(d[k]!=inf){
		cout<<d[k];
	}else{
		cout<<-1;
	}
}
