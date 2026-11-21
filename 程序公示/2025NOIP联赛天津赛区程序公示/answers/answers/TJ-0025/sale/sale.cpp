#include <iostream>
using namespace std;
const long long mod = 998244353;
long long c,t,n,m,a;
long long qpow(long long x,long long y)
{
	long long res = 1;
	while(y > 0)
	{
		if(y & 1)
			res = res*x%mod;
		y>>=1;
		x = x*x%mod;
	}
	return res;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>m;
		for(long i = 1;i <= n;i++)
			cin>>a;
		cout<<qpow(2,n)<<endl;
	}
	return 0;
}
