#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005],b[100005],c[100005];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],c[i]=a[i]+b[i];
	sort(a+1,a+n+1);
	sort(c+1,c+n+1);
	long long ans=0,pre=0,d=c[1];
	for(int i=0;i<=n;i++)
	{
		pre+=a[i];
		if(pre>m)
			break;
		ans=max(ans,i+(m-pre)/d*2);
	}
	cout<<ans;
	return 0;
}
