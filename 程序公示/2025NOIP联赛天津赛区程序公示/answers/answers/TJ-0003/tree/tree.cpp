#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> e[8005];
int sz[8005],dp[380][380][380],f[380][380][380],tmp[380][380][380];
//考虑对于每一个点，你可以设定一个权值
//你可以设定为待定，也可以设定为其子树中权值最大的数加上其子树中0的数量+1
//答案为所有权值之和
//考虑dp
//f[i][j][k]代表i节点子树中 最大 权值为j（不包含自己），子树中共有k个待定的最大子树总贡献（不包括自己） 
//dp[i][j][k]代表i节点最大权值为 j（包括自己） 子树中共有k个待定 
//转移的时枚举 dp[sum][j][k] 
//待定数量折现，待定数量清零 
void dfs(int id)
{
	f[id][0][0]=0;
	for(int i:e[id])
	{
		dfs(i);
		for(int j=0;j<=sz[id]+sz[i];j++)
			for(int k=0;k<=sz[id]+sz[i];k++)
				tmp[id][j][k]=f[id][j][k];
		for(int j=0;j<=sz[id];j++)
			for(int k=0;k<=sz[id];k++)
				for(int s=0;s<=sz[i];s++)
					for(int t=0;t<=sz[i];t++)
					{
						//权值取max  j,s
						//0相加  k+t
						//答案相加
						int nj=max(j,s),nk=k+t;
						tmp[id][nj][nk]=max(tmp[id][nj][nk],f[id][j][k]+dp[i][s][t]); 
					}
		for(int j=0;j<=sz[id]+sz[i];j++)
			for(int k=0;k<=sz[id]+sz[i];k++)
				f[id][j][k]=max(f[id][j][k],tmp[id][j][k]);
		sz[id]+=sz[i];
	}
	sz[id]++;
	for(int j=0;j<=sz[id];j++)
		for(int k=0;k<=sz[id];k++)
		{
			//自己选待定 
			dp[id][j][k+1]=max(dp[id][j][k+1],f[id][j][k]);
			//自己选最大的权值
			dp[id][j+k+1][0]=max(dp[id][j+k+1][0],f[id][j][k]+j+k+1); 
		}
	return ;
}
int mian()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		e[i].clear(); 
	for(int i=2;i<=n;i++)
	{
		int fa;
		cin>>fa;
		e[fa].push_back(i);
	}
	memset(dp,-0x3f,sizeof(dp));
	memset(tmp,-0x3f,sizeof(tmp));
	memset(f,-0x3f,sizeof(f));
	memset(sz,0,sizeof(sz));
	dfs(1);
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			ans=max(ans,dp[1][i][j]);
	cout<<ans<<"\n";
	return 0;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
		mian();
	return 0;
}
