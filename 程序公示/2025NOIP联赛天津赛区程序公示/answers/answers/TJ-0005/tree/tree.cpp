#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define mid ((l+r)>>1)
using namespace std;
const int N=8080+5,mod=998244353;
int n,m,fa[N],a[N],f[N][N],ff[N],siz[N];
vector<int>g[N];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
void dfs(int u){
	if(g[u].empty()){
		f[u][1]=1;
		siz[u]=1;
		return;
	}
//	siz[u]=1;f[u][1]=1;
	for(auto v:g[u]){
		dfs(v);
		if(siz[u]<siz[v]) swap(siz[u],siz[v]),swap(f[u],f[v]);
		memcpy(ff,f[u],sizeof(f[u]));
		siz[u]+=siz[v];
		int maxn=0;
		for(int i=1;i<=siz[u];i++){
			maxn=max(maxn,f[v][i]);
			f[u][i]+=maxn;
		}
		for(int i=siz[u];i>=siz[v];i--){
			f[u][i]=max(f[u][i],ff[i-siz[v]]);
//			f[u][i]=max(f[u][i],ff[i-siz[v]]+siz[v]);
		}
//	printf("%d: ",u);
//	for(int i=1;i<=siz[u];i++) printf("%d ",f[u][i]);
//	puts("");
	}
	siz[u]++;
	for(int i=siz[u];i>=1;i--) f[u][i]=max(f[u][i]+i,f[u][i-1]+i);
//	printf("%d: ",u);
//	for(int i=1;i<=siz[u];i++) printf("%d ",f[u][i]);
//	puts("");
}
void dfs0(int u){
	siz[u]=1;
	for(auto v:g[u]){
		dfs0(v);
		siz[u]+=siz[v];
	}
}
void solve(){
	dfs0(1);
	int num=0;
	for(auto v:g[1]){
		a[++num]=siz[v];
//		printf("%d ",a[num]);
	}
	int ans=0,maxn=0;
	for(int i=1;i<=num;i++) ans+=(a[i]==1?1:a[i]+1),maxn=max(maxn,a[i]);
	printf("%lld\n",ans+maxn+1);
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
//	int cc=clock();
	int T=read();
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++) g[i].clear(),siz[i]=0;
		for(int i=1;i<=n;i++) for(int j=0;j<=n;j++) f[i][j]=0;
		for(int i=2;i<=n;i++){
			fa[i]=read();
			g[fa[i]].emplace_back(i);
		}
		if(m==2){
			solve();
			continue;
		}
		dfs(1);
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,f[1][i]);
		printf("%lld\n",ans);
	}
//	printf("\n%lld",clock()-cc);
	return 0;
}
/*
5
13 12
1 1 3 4 5 5 7 7 9 9 6 12
13 12
1 2 2 2 3 5 4 4 3 4 3 4
13 12
1 1 2 2 3 3 4 1 9 10 1 12
13 12
1 2 1 3 3 6 6 7 8 9 10 10
13 12
1 1 2 2 5 4 6 6 8 9 9 12

*/
