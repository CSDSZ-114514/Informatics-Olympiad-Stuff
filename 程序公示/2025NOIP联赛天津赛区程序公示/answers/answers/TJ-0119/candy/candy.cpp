#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[3005],dp[10005];
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i+n]>>a[i+n+n],a[i]=a[i+n]+a[i+n+n];
	bool f=0;
	for(int i=1;i<=n;i++,f=!f)
		for(int j=a[i];j<=m;j++)
			dp[j]=max(dp[j],dp[j-a[i]]+2);
	for(int i=n+1;i<=n*2;i++,f=!f)
		for(int j=m;j>=a[i];j--)
			dp[j]=max(dp[j],dp[j-a[i]]+1);
	cout<<dp[m];
	return 0;
}

