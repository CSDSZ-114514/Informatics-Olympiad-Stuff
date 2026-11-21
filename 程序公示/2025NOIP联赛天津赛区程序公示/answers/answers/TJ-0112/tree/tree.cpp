#include<bits/stdc++.h>
using namespace std;

const int N=8e3+10,inf=-0x3f3f3f3f;

int dp[N][N],n,m,fa[N],e[N],E[N],vos[N],lst[N],Nxt[N],nxt[N],maxa[N][N],up[N][N],sz[N],dp2[N][N];

void init(){
	memset(dp,0,sizeof dp);
	memset(fa,0,sizeof fa);
	memset(vos,0,sizeof vos);
	memset(lst,0,sizeof lst);
	memset(Nxt,0,sizeof Nxt);
	memset(nxt,0,sizeof nxt);
	memset(maxa,0,sizeof maxa);
	memset(up,0,sizeof up);
	memset(sz,0,sizeof sz);
	return ;
}

void DFS(int x){
	sz[x]=1;
	dp[x][0]=1;
	dp2[x][0]=1;
	for(int i=1;i<=n;i++){
		dp[x][i]=inf;
	}
	if(Nxt[x]){
		DFS(Nxt[x]);
		int v=Nxt[x];
		sz[x]+=sz[v];
		dp[x][0]=max(dp[x][0],dp[v][0]+1);
		for(int i=1;i<=n;i++){
			dp[x][i]=max(dp[x][i],dp[v][i]+i+1);
			dp[x][i]=max(dp[x][i],dp[v][i-1]+i+1);
			dp2[x][i]=max(dp2[x][i],dp2[v][i-1]+i+1);
		}
	}
	if(nxt[x]){
		DFS(nxt[x]);
		int v=nxt[x];
		sz[x]+=sz[v];
		if(Nxt[x]){
			int l=Nxt[x];
			dp[x][0]=max(dp[x][0],dp[l][0]+dp[v][0]+1);
			for(int i=1;i<=n;i++){
				if(i>sz[l]+sz[v]+1)continue;
				dp2[x][i]=max(dp2[x][i],dp2[v][i-1]);
				dp[x][i]=max(max(dp[l][i],dp[l][i-1])+i+1+max(0,maxa[v][n]),dp[x][i]);
				dp[x][i]=max(max(dp[v][i],dp[v][i-1])+max(up[l][i],dp[l][i-1]+1),dp[x][i]);//
				//if(i>sz[l] && sz[v]-(i-sz[l]-1)-1>=0)dp[x][i]=max(dp[x][i],max(up[l][i],dp[l][i-1]+1)+dp[v][sz[v]-(i-sz[l]-1)-1]);
			}
		}else{
			dp[x][0]=max(dp[x][0],dp[v][0]+1);
			for(int i=1;i<=n;i++){
				dp[x][i]=max(dp[x][i],dp[v][i]);
				dp[x][i]=max(dp[x][i],dp[v][i-1]);
			}
		}
	}
	maxa[x][0]=dp[x][0];
	for(int i=1;i<=n;i++){
		maxa[x][i]=max(maxa[x][i-1],dp[x][i]);
		//if(x==2)cout<<dp[x][i]<<' '<<i<<endl;
	}
	up[x][0]=dp[x][0]+1;
	for(int i=1;i<=n;i++){
		up[x][i]=max(up[x][i-1],dp[x][i]+i+1);//
	}
	for(int i=1;i<sz[x];i++){
		dp[x][i]=max(dp[x][i],dp[x][sz[x]-1-i]);
	}
	return ;
}

signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		init();
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			if(!vos[fa[i]]){
				E[i]=fa[i];
				vos[fa[i]]=1;
				lst[fa[i]]=i;
				Nxt[fa[i]]=i;
			}else{
				e[i]=lst[fa[i]];
				nxt[lst[fa[i]]]=i;
				lst[fa[i]]=i;
			}
		}
		DFS(1);
		cout<<maxa[1][n]<<endl;
	}
	
	return 0;
}
