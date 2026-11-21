#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
ll x[N],y[N];
ll n,m,minn=1e18,ans;
int main()
{
	freopen("candy.in","r",stdin); 
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		minn=min(minn,x[i]+y[i]);
	} 
	ans=(m/minn)*2;
	sort(x+1,x+1+n);
	for(int i=1;i<=n;i++){
		m-=x[i];
		if(m<0) break;
		ans=max(ans,i+(m/minn)*2);
	}
	cout<<ans;
	return 0;
}
