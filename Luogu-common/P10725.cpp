#include<bits/stdc++.h>
using namespace std;
long long n,f[100005][2],ans;int isbl[100005];
vector<long long> e[100005];
void dfs(int u, int father) {
	if(isbl[u] ==1){
		f[u][1]=0;f[u][0]=-1e9;
	}else{
		f[u][0]=0;f[u][1]=-1e9;
	}
	for(int v:e[u]){
		if(v!=father){
			dfs(v,u);
			ans=max(ans,max(f[u][0]+f[v][1]+1,f[u][1]+f[v][0]+1));
			f[u][0]=max(f[u][0],f[v][0]+1);
			f[u][1]=max(f[u][1],f[v][1]+1);
			//ans=max(ans,max(f[u][0]+f[v][1]+1,f[u][1]+f[v][0]+1));
		}
	}
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>isbl[i];
	}
	for(int i=1;i<=n-1;i++){
		long long a,b;cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
