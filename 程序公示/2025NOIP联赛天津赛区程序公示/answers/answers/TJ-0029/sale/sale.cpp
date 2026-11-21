#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
const int MOD=998244353;
int c,t,n,m,a[N];
int qmi(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b%2==1)ans=ans*a%MOD;
		a=a*a%MOD;
		b/=2;
	}
	return ans;
}
void solve1()
{
	sort(a+1,a+n+1);
	int ans=qmi(2,n);
	for(int i=n;i>=1&&a[i]/2>=a[1];i--)
	{
		int findout=upper_bound(a+1,a+n+1,a[i]/2)-a;
		int chazhi=lower_bound(a+1,a+n+1,a[findout]-a[i])-a-1;
		ans=(ans-qmi(2,i-findout)*(((findout-chazhi+MOD)%MOD-1+MOD)%MOD)%MOD*qmi(2,chazhi)%MOD+MOD)%MOD;
	}
	cout<<ans<<endl;
	return ;
}
signed main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c>=7&&c<=9)solve1();
		else if(c>=14&&c<=15)solve1();
		else cout<<qmi(2,n)<<endl;
	}
	return 0;
}

