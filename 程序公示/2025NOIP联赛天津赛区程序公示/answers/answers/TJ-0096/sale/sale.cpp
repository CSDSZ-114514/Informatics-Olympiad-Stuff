#include<bits/stdc++.h>
using namespace std;
int n,m;
void solveA()
{
	long long ans=1;
	for(int I=0;I<n;I++)
	{
		ans*=2;
		ans%=998244353;
	}
	cout<<ans<<endl;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out"."w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t>>t;
	for(int T=0;T<t;T++)
	{
		cin>>n>>m;
		int a[n];
		for(int I=0;I<n;I++) cin>>a[I];
		bool the_same=true;
		for(int I=1;I<a;I++)
			if(a[I]!=a[I-1])
			{
				the_same=false;
				break;
			}
		if(the_same) solveA();
		else cout<<1<<endl;
	}
	
	return 0;
}
