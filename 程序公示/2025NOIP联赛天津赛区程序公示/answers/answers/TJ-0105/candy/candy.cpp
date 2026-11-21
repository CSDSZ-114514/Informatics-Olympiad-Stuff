#include <bits/stdc++.h>
using namespace std;
int a[100005];
struct candy
{
	long long x,y;
	int id;
}c[100005];
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,sum=0,s=0,g;
	long long M=2000000001;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		
		c[i].id=i;
		cin>>c[i].x>>c[i].y;
		a[i]=c[i].x;
		if(c[i].x+c[i].y<M)
		{
			M=min(c[i].x+c[i].y,M);
			g=i;
		}
	}
	a[g]=c[g].y;
	sort(a+1,a+1+n);
	if(n==1)
	{
		long long chu=m/(c[1].x+c[1].y);
		long long yu=m%(c[1].x+c[1].y);
		if(yu>=c[1].x)
			cout<<chu*2+1;
		else
			cout<<chu*2;
		
	}
	long long chu=m/M;
	long long chuy=chu*2-1;
	long long yu=m%M+c[g].y;
	while(yu-a[s+1]>=0&&s+1<=n)
	{
		yu-=a[s+1];
		s++;
	}
	cout<<chuy+s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

