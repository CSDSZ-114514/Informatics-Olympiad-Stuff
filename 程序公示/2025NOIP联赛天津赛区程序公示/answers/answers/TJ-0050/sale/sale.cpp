#include<bits/stdc++.h>
using namespace std;

#define MOD 998244353

int c,T;
int n,m,a[10000];
long long C[5010][5010],ans;

long long ppow(int x)
{
	if(x==0)return 1;
	return (x%2==1)?(2*ppow(x>>1)*ppow(x>>1))%MOD:(ppow(x>>1)*ppow(x>>1))%MOD;
}
void init()
{
	C[0][0]=1;
	C[1][0]=C[1][1]=1;
	for(int i=2;i<=5000;++i)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<5000;++j)
		{
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
		}
	}
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	scanf("%d %d",&c,&T);
	init();

	while(T--)
	{
		scanf("%d %d",&n,&m);

		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
		}
		
		for(int i=1;i<=n;i+=2)
		{
			ans+=C[n][i];
			ans%=MOD;
		}
		
		printf("%lld\n",(ppow(n)-ans+MOD)%MOD);
	}
	
	return 0;
}

