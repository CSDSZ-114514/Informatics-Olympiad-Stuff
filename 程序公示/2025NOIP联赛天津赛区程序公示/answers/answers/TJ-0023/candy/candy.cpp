#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,m,x,y,c=1e9,s[N],ans;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		c=min(c,x+y);
		s[i]=x;
	}
	sort(s+1,s+n+1);
	s[0]=0;
	for(int i=0;i<=n;i++)
	{
		m-=s[i];
		if(m<=0) break;
		ans=max(ans,m/c*2+i);
	}
	cout<<ans;
	return 0;
}
//RP++;
