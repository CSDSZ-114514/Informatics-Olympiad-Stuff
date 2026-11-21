#include <bits/stdc++.h>
using namespace std;
// #define int long long
// #define M 2000006 // 2e6
#define M 370
int T,n,m,fa[M],siz[M],ans;
int f[M][M][M],g[M][M][M],h[M][M];
std::vector<int>G[M];
void CLEAR() {
	memset(f,0xc0,sizeof f),memset(g,0xc0,sizeof g);
	for(int i=1;i<=n;i++) G[i].clear(),siz[i]=fa[i]=0;
	ans=0;
}
void dfs(int x=1) {
	siz[x]=1;
	f[x][0][1]=0,g[x][0][1]=0,g[x][0][0]=0;
	f[x][1][0]=0,g[x][1][0]=g[x][1][1]=0;
	for(int v:G[x]) {
		dfs(v),memcpy(h,f[x],sizeof h);
		for(int i=0;i<=siz[x];i++) {
			for(int j=0;j<=siz[v];j++) {
				for(int mx=0;mx<=siz[x];mx++)
					h[i+j][mx]=std::max(h[i+j][mx],f[x][i][mx]+g[v][j][std::min(siz[v],mx)]);
				for(int mx=0;mx<=siz[v];mx++)
					h[i+j][mx]=std::max(h[i+j][mx],f[v][j][mx]+g[x][i][std::min(siz[x],mx)]);
			}
		} siz[x]+=siz[v];
		memcpy(f[x],h,sizeof h);
		for(int i=0;i<=siz[x];i++)
			for(int j=0;j<=siz[x];j++)
				g[x][i][j]=std::max(f[x][i][j],(j?g[x][i][j-1]:0));
	}
	for(int j=siz[x];j>=0;j--) {
		for(int i=1;i+j<=siz[x];i++) {
			for(int p=1;p<=i;p++) {
				f[x][i-p][j+p]=std::max(f[x][i-p][j+p],f[x][i][j]);
			}
		}
	}
	for(int i=0;i<=siz[x];i++) for(int j=0;j<=siz[x];j++) {
		f[x][i][j]+=j,g[x][i][j]=std::max(f[x][i][j],(j?g[x][i][j-1]:0)),ans=std::max(ans,f[x][i][j]);
		// std::cout<<x<<' '<<i<<' '<<j<<' '<<f[x][i][j]<<'\n';
	}
}
signed main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>T;
	while(T--) {
		CLEAR();
		std::cin>>n>>m;
		for(int i=2;i<=n;i++) std::cin>>fa[i],G[fa[i]].push_back(i);
		dfs();
		std::cout<<ans<<'\n';
	}
	return 0;
}

/*

*/