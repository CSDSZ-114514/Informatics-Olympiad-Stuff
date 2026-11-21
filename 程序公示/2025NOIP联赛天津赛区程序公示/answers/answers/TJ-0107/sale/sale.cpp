#include<bits/stdc++.h>
using namespace std;
long long c,t,n,m;
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>t>>n>>m;
	long long a[n]={};
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	long long ans=pow(2,n)-1;
	sort(a,a+n);
	cout<<ans-1;
	return 0;
 } 
