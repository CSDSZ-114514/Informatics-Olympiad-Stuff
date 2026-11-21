#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long dfn[1000005],low[1000005],tot;
vector<int> e[1000005];
long long siz[1000005],cut[1000005],ans[1000005];
void tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	int child = 0;
	siz[u]=1;
	int sum=0;
	for(int v:e[u]) { 
		if(!dfn[v]) { 
			tarjan(v);
			low[u] = min(low[u], low[v]);	
			siz[u]+=siz[v];
			if(low[v] >= dfn[u]) {  
				sum+=siz[v];
				ans[u]+=siz[v]*(n-siz[v]);
			}
		} else {
			low[u] = min(low[u], dfn[v]); 
		}
	}
	ans[u]+=(n-1-sum)*(sum+1)+(n-1);
} 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long a,b;
		cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		//memset(ans,0,sizeof(ans));
		if(!dfn[i]){
			tarjan(i);
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<endl;
	}
}
