#include <bits/stdc++.h>
#define MAXN 100100
using namespace std;
long long n=0,m=0,mark=0;
long long sum=0x3f3f3f3f;
struct price
{
	long long x;
	long long y;
};
price p[MAXN];
long long ans;
bool cmp(price a,price b)
{
	return a.x<b.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);

	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++)
		{
			cin >> p[i].x >> p[i].y;
			if((p[i].x+p[i].y)<sum)
				{
					mark=i;
					sum=p[i].x+p[i].y; 
				}
		}
	long double sump=sum/2;  
	sort(p+1,p+1+n,cmp);
	
	for(int i=1; i<=n; i++)
		{
			if(p[i].x<=sump&&m-p[i].x>=0) 
			{
				m-=p[i].x; 
				ans++;
			}
			else
				{
					break;
				}
		}
	long double tmp=1.0*m/sum; 
	ans+=tmp*2; 
	cout << ans;
	return 0;
}
