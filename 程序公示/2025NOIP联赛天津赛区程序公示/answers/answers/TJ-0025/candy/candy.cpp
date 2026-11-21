#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define endl '\n'
using namespace std;
long long n,m,ansmax,ansa,ans,nowodd;
long long a[100050];
long long b[100050];
long long c[2];
priority_queue<long long,vector<long long>,greater<long long> > q;
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	ansmax = 2e9+100;
	for(long long i = 1;i <= n;i++)
	{
		cin>>a[i]>>b[i];
		q.push(a[i]);
		if(ansmax > a[i]+b[i])
		{
			ansmax = min(ansmax,a[i]+b[i]);
			ansa = a[i];
			c[0] = a[i];
			c[1] = a[i];
		}
	}
	ans = m/ansmax*2;
	m%=ansmax;
	long long tmp = ans; 
	while(true)
	{
		if(m < q.top())
			break;
		m-=q.top();
		ans++;
		q.pop();
		//cout<<ans<<endl;
	}
	q.push(ansa);
	for(long long i = 0;i < tmp;i++)
	{
		long long nowans = ans-2;
		m+=ansmax;
		while(!q.empty())
		{
			if(m < q.top())
				break;
			m-=q.top();
			q.pop();
			nowans++;
		}
		//cout<<nowans<<endl;
		if(nowans < ans)
			break;
		else
			ans = nowans;
	}
	cout<<ans<<endl;
	return 0;
}
