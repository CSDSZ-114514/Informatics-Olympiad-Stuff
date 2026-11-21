#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
vector <int> g[1005];
int de[1005];
int sz[1005];
long long dp[1005][1005];
long long mx[1005][1005];
void dfs1(int x){
	de[x]=0;
	sz[x]=1;
	for (int i=0;i<g[x].size();i++){
		int t=g[x][i];
		dfs1(t);
		sz[x]+=sz[t];
		de[x]=max(de[x],de[t]+1);
	}
}
void dfs(int x){
	for (int i=0;i<g[x].size();i++){
		int t=g[x][i];
		dfs(t);
	}
	if (de[x]==1){
		dp[x][0]=mx[x][0]=sz[x];
		for (int i=1;i<sz[x];i++) dp[x][i]=sz[x]+1;
		for (int i=1;i<=n;i++) mx[x][i]=max(mx[x][i-1],dp[x][i]);
		return ;
	}
	for (int i=0;i<sz[x];i++){
		long long sum=0;
		for (int j=0;j<g[x].size();j++){
			int t=g[x][j];
			sum+=mx[t][i];
		}
		for (int j=0;j<g[x].size();j++){
			int t=g[x][j];
			if (i==0) dp[x][i]=max(dp[x][i],sum-mx[t][i]+dp[t][i]);
			else dp[x][i]=max(dp[x][i],sum-mx[t][i]+max(dp[t][i],dp[t][i-1]));
		}
		dp[x][i]+=i+1;
		if (i==0) mx[x][i]=dp[x][i];
		else mx[x][i]=max(mx[x][i-1],dp[x][i]);
	}
	for (int i=sz[x];i<=n;i++) mx[x][i]=mx[x][i-1];
}
void work(){
	cin>>n>>m;
	for (int i=2;i<=n;i++){
		int x;
		scanf("%d",&x);
		g[x].push_back(i);
	}
	dfs1(1);
	dfs(1);
	cout<<mx[1][n]<<"\n";
	for (int i=1;i<=n;i++){
		for (int j=0;j<=n;j++){
			dp[i][j]=mx[i][j]=0;
		}
	}
	for (int i=1;i<=n;i++) g[i].clear();
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	int t;
	cin>>t;
	while (t--) work(); 
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

