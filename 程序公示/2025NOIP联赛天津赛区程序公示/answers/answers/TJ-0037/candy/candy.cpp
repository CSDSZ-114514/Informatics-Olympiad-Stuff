#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,p[100005][2],np[100005],mn_sum=90000000000000,ans;
bool spf=1;
struct p11
{
	int val;
	int no;
	int other;
}p1[100005];
bool way(p11 a,p11 b)
{
	if(a.val==b.val) return a.other<b.other;
	return a.val<b.val;
}
signed main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i][0]>>p[i][1];
		p1[i].val=p[i][0];
		p1[i].no=i;
		p1[i].other=p[i][1];
		if(p[i][0]!=p[i][1]) spf=0;
		mn_sum=min(mn_sum,p[i][0]+p[i][1]);
	}
	/*tst candy 6
	for(int i=1;i<=n;i++) if(p[i][0]+p[i][1]==mn_sum) cout<<'t'<<i<<'t';
	*/
	if(spf)
	{
		cout<<m/(mn_sum/2);
		return 0;	
	}
	sort(p1+1,p1+n+1,way);
	for(int i=1;(i+1)<=n;i+=2)
	{
		if(p1[i].val+p1[i+1].val>mn_sum) break;
		if(m<p1[i].val+p1[i+1].val) break;
		ans+=2;
		m-=p1[i].val+p1[i+1].val;
		np[p1[i].no]=np[p1[i+1].no]=1;
	}
	ans+=(m/mn_sum)*2;
	for(int i=1;i<=n;i++)
	{
		if(p[i][np[i]]<=(m%mn_sum))
		{
			ans++;
			break;
		}
	}
	cout<<ans;
	return 0;
} 
