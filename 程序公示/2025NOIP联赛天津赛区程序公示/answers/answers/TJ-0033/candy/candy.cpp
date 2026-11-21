#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N =5e7+5;
int n,m,x[N],y[N],dp[N];
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
		y[i]+=x[i];
		dp[i]=0;
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=x[i];--j){
			dp[j]=max(dp[j],dp[j-x[i]]+1);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=m;j>=0;--j){
			for(int num=1;num*y[i]<=j;++num){
				dp[j]=max(dp[j],dp[j-y[i]*num]+num*2);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=m;i++){
		ans=max(ans,dp[i]);
	}
	cout<<ans<<'\n';
	cout.flush();
	return 0;
}

