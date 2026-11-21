#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,m,a[N],b[N],minn=LONG_LONG_MAX,sum,cnt,ans,zuhe;
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		minn=min(minn,a[i]+b[i]);
	}
	ans=m/minn*2;m=m%minn;
	sort(a+1,a+n+1);
	for(cnt=1;cnt<=n;cnt++)
	{
		sum+=a[cnt];
		if(sum>minn)
		{
			int temp=cnt-1-zuhe;zuhe=cnt-1;
			if(temp>=2)
			{
				int tmp=sum-a[cnt];
				m+=(minn-tmp);ans+=(temp-2);
				sum=a[cnt]; 
			}
			else{cnt--;break;}
		}
	}
	ans+=(m/minn*2);m=m%minn;
	for(;cnt<=n&&a[cnt]<=m;cnt++){ans++;m-=a[cnt];}
	cout<<ans<<endl;
	return 0;
}
