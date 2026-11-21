#include<bits/stdc++.h>
using namespace std;
long long n,m,rd[5000005];
vector<int> ed[5000005];
stack<int> s;
long long dfn[5000005],low[5000005],tot,scc[5000005],siz[5000005],cnt;
void tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	s.push(u);
	for(int v:ed[u]) { 
		if(!dfn[v]) {
			tarjan(v); 
			low[u] = min(low[u], low[v]); 
		} else if(!scc[v]) {
			low[u] = min(low[u],dfn[v]);
		} 
	}
	if(dfn[u] == low[u]) { 
		++cnt; 
		while(true) {
			int h = s.top(); 
			s.pop();
			scc[h] = cnt; 
			siz[cnt]++; 
			if(h == u) { 
				break;
			}
		}
	}
}
long long grd[10005],gcd1[10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a=9;
		while(true){
			cin>>a;
			if(a!=0)ed[i].push_back(a);
			else break;
		}
	}
	for(int i=1;i<=n;i++){
		if(!dfn[i]){
			tarjan(i);
		}
	}
//	long long ans1=cnt;
//	for(int i=1;i<=n;i++){
//		if(rd[i]==0){
//			ans1++;
//		}
//	}
	for(int i=1; i<=n; i++) {
		for(int v:ed[i]) { 
			if(scc[i] != scc[v]) {
				grd[scc[v]]++;gcd1[scc[i]]++;
			}
		}
	}
	long long srd=0,scd=0;
	for(int i=1;i<=cnt;i++){
		if(grd[i]==0)srd++;
		if(gcd1[i]==0)scd++;
	}

	cout<<srd<<endl;
	if(cnt==1){
		cout<<0;
	}else{
		cout<<max(srd,scd);
	}
	return 0;
}
