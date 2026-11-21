#include<bits/stdc++.h>
using namespace std;
const int NR=1e5+10;
const int MR=1e1+10;
int n,m;
struct node{
	int x,y,num;
}a[NR];
struct NODE{
	int val,num;
	bool flag;
}c[2*NR];
bool fp[2*NR];
bool cmp2(node x,node y)
{
	return x.x+x.y<y.x+y.y;
}
bool cmp3(NODE x,NODE y)
{
	return x.val<=y.val;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin>>n>>m;
	int cn=0;
	bool flag1=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
		a[i].num=i;
		c[cn++].val=a[i].x,c[cn].num=i,c[cn].flag=1;
		c[cn++].val=a[i].y,c[cn].num=i,c[cn].flag=0;
		if(a[i].x!=a[i].y) flag1=0;
	}
	if(flag1)
	{
		sort(a+1,a+n+1,cmp2);
		cout<<m/a[1].x;
		return 0;
	}
	int ans=0;
	sort(a+1,a+n+1,cmp2);
	ans+=m/(a[1].x+a[1].y);
	ans*=2;
	m%=(a[1].x+a[1].y);
	sort(c+1,c+cn+1,cmp3);
	while(m>0)
	{
		for(int i=1;i<=2*n;i++)
		{
			if((c[i].flag==1||fp[i]==1)&&c[i].val<=m)
			{
				m-=c[i].val;
				c[i].flag=0;
				fp[c[i].num]=1;
				ans++;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

