#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=150;
int t,n,m,p[N],dp[N][N][N],sz[N];
vector<int>e[N];
void dfs(int u,int fa){
	int f[N][N],g[N][N];
	sz[u]=1;
	for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)g[i][j]=-1e12;
	g[0][1]=0;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		for(int i=0;i<=sz[u];++i)for(int j=0;j<=sz[u];++j)f[i][j]=g[i][j];
		for(int i=0;i<=n;++i)for(int j=0;j<=n;++j)g[i][j]=-1e12;
		for(int k=sz[v];k>=0;--k){
			for(int l=sz[v];l>=0;--l){
				if(dp[v][k][l]<0)continue;
				for(int i=sz[u];i>=0;--i){
					for(int j=sz[u];j>=0;--j){
						g[max(i,k)][j+l]=max(g[max(i,k)][j+l],f[i][j]+dp[v][k][l]);
					}
				}
			}
		}	
	}
	


	for(int j=0;j<=sz[u];++j)for(int k=0;k<=sz[u];++k)dp[u][j][k]=g[j][k];
	for(int j=0;j<=sz[u];++j){
		for(int k=0;k<=sz[u];++k){
			if(j)dp[u][j][k]=max(dp[u][j][k],dp[u][j-1][k+1]);
		}
	}
	for(int j=0;j<=sz[u];++j){
		for(int k=0;k<=sz[u];++k){
			dp[u][j][k]+=j;
		}
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=0;i<=n+10;++i)for(int j=0;j<=n+10;++j)for(int k=0;k<=n+10;++k)dp[i][j][k]=-1e12;
		for(int i=2;i<=n;++i){
			cin>>p[i];
			e[i].push_back(p[i]);
			e[p[i]].push_back(i);
		}
		dfs(1,0);
		int ans=0;
//		for(int i=1;i<=n;++i){
//			cout<<i<<":";
//			for(int j=0;j<=n;++j){
//				for(int k=0;k<=n;++k){
//					if(dp[i][j][k]>=0)cout<<"("<<i<<" "<<j<<' '<<k<<")"<<dp[i][j][k]<<'\n';
//				}
//			}
//		}
		for(int i=0;i<=n;++i){
			for(int j=0;j<=n;++j){
				ans=max(ans,dp[1][i][j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0; 
} 
