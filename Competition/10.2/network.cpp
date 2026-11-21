#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct ED{
	long long v,w;
};
vector<ED> e[1000005];
long long lfc[1000005],f[3005][3005],c[1000005];
void dfs(long long u){
	
	if(u>=n-m+1){
		lfc[u]=1;
		f[u][1]=c[u];
		return ;
	}
	lfc[u]=0;
	for(auto t:e[u]){
		dfs(t.v);
		for(int i=lfc[u]+lfc[t.v];i>=0;i--){
			for(int k=1;k<=lfc[t.v];k++){
				if(f[u][i-k]==-1e18)continue;
				f[u][i]=max(f[u][i],f[u][i-k]+f[t.v][k]-t.w);
			}
		}
		lfc[u]+=lfc[t.v];
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n-m;i++){
		long long k;cin>>k;
		for(int j=1;j<=k;j++){
			long long a,c;
			cin>>a>>c;
			e[i].push_back({a,c});
		}
	}
	
	for(int i=n-m+1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=-1e18;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][0]=0;
	}
	dfs(1);
	
	for(int i=n;i>=1;i--){
		if(f[1][i]>=0){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
