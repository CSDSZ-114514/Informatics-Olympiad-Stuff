#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct node{
	int x,y;
}a[N],b[N];
int n,k;
long long minn=2e9+5;
long long m;
long long ans;
bool cmp(node b,node c)
{
	return b.x<c.x;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		cin>>a[i].x>>a[i].y;
		minn=min(minn,(long long)(a[i].x+a[i].y));
		if(a[i].x<=a[i].y) b[++k].x=a[i].x,b[k].y=a[i].y;
	}
	sort(b+1,b+k+1,cmp);
	ans=m/minn*2;
	long long s=0;
	for(int i=1;i<=k;i++)
	{
		int v=b[i].x;
		s+=v;
		if(m<s) break;
		ans=max(ans,(m-s)/minn*2+i);
	}
	cout<<ans;
	return 0;
} 
