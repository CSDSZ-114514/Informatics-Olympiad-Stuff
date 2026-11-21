#include<bits/stdc++.h>
using namespace std;
const int N=4e2+25;

int cnt,hd[N],to[N],pre[N];
void add(int u,int v){
	++cnt;
	to[cnt]=v;
	pre[cnt]=hd[u];
	hd[u]=cnt;
}
int n,m;

//bool hv[N];
int nu[N];
int ans;
bool szhv[N][N];
int nans;
void gt(int u){
	szhv[u][nu[u]]=1;
	for (int i=hd[u];i;i=pre[i]){
		int v=to[i];
		gt(v);
		for (int j=0;j<n;++j){
			szhv[u][j]|=szhv[v][j];
		}
	}
	int np=0;
	while (szhv[u][np]) ++np;
	nans+=np;
}
void dfs(int lev){
	if (lev==n+1){
		memset(szhv,0,sizeof(szhv));
		nans=0;
		gt(1);
		ans=max(nans,ans);
		return;
	}
	for (int i=0;i<n;++i){
		//if (!hv[i]){
		//	hv[i]=1;
			nu[lev]=i;
			dfs(lev+1);
		//	hv[i]=0;
		//}
	}
}

void solve(){
	cnt=0;
	ans=0;
	memset(hd,0,sizeof(hd));
	cin>>n>>m;
	for (int i=2;i<=n;++i){
		int u,v=i;
		cin>>u;
		add(u,v);
	}
	dfs(1);
	cout<<ans<<'\n';
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
	int t;
	cin>>t;
	while (t--) solve();
	return 0;
}
