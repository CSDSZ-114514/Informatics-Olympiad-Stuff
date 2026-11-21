#include<bits/stdc++.h>
using namespace std; 
#define ll long long
struct candy
{
	ll x,y;
	double av;
	bool flag;
};
candy a[100010];
bool cmp1(candy f,candy g)
{
	return f.av<g.av;
}
bool cmp2(candy f,candy g)
{
	return f.x<g.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	bool flag1=0;
	int n;
	ll m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].av=(1.0*(a[i].x+a[i].y))/2;
		a[i].flag=0;
		if(flag1)	continue;
		if(a[i].x!=a[i].y)	flag1=1;
	}
	sort(a+1,a+n+1,cmp1);
	if(flag1==0)
	{
		int c=m/a[1].x;
		cout<<c;
		return 0;
	}
	a[1].flag=1;
	double ava=a[1].av;
	sort(a+1,a+n+1,cmp2);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i].x>ava)	break;
		if(m-a[i].x>=0)	
		{
			cnt++;
			m-=a[i].x;
			swap(a[i].x,a[i].y);
		}
		else
		{
			cout<<cnt;
			return 0;
		}
	}
	while(1)
	{
		if(m-2*ava>=0)
		{
			cnt+=2;
			m-=2*ava;
		}
		else
		{
			sort(a+1,a+n+1,cmp2);
			for(int i=1;i<=n;i++)
			{
				if(m-a[i].x>=0)
				{
					cnt++;
					m-=a[i].x;
					swap(a[i].x,a[i].y);
				}
				else
				{
					cout<<cnt;
					return 0;
				}
			}
		}
	}
	return 0;
}
