#include<bits/stdc++.h>
using namespace std;
const int NR=5e3+10;
const int MR=1e1+10;
int n,m;
struct node{
	int w,x,vis;
	double b;
}a[NR];
int ans;
int mx1[NR],mx2[NR];
bool cmp1(node x,node y)
{
	return x.b>y.b;
}
bool cmp2(node x,node y)
{
	return x.w>y.w;
}
bool cmp3(char x,char y)
{
	return x<y;
}
bool check()
{
	for(int i=1;i<=n;i++)
	{
		if(mx1[i]!=mx2[i]) return false;
	}
	return true;
}
void dfs(int step,string S)
{
	if(step==n)
	{
		memset(mx1,0,sizeof(mx1));
		memset(mx2,0,sizeof(mx2));
		for(int i=1;i<=n;i++) 
		{
			a[i].vis=(S[i]-'0');
			a[i].b=a[i].w*1.0/a[i].vis;
		}
		sort(a+1,a+n+1,cmp1);
		int k=m,t=0,abb=0;
		while(k>0&&t<=n)
		{
			t++;
			if(a[t].vis<=k)
			{
				mx1[++abb]=('0'+a[t].x);
				k-=a[t].vis;
			}
		}
		sort(a+1,a+n+1,cmp2);
		k=m,t=0,abb=0;
		while(k>0&&t<=n)
		{
			t++;
			if(a[t].vis<=k)
			{
				mx2[++abb]=('0'+a[t].x);
				k-=a[t].vis;
			}
		}
		sort(mx1+1,mx1+abb+1);
		sort(mx2+1,mx2+abb+1);
		if(check()) ans++;
		return ;
	}
	dfs(step+1,S+'1');
	dfs(step+1,S+'2');
	return ;
}
int main()
{
	freopen("sale.in","r",stdin); 
	freopen("sale.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i].w,a[i].x=i;
		ans=0;
		dfs(0," ");
		cout<<ans<<"\n";
	}
	return 0;
}
