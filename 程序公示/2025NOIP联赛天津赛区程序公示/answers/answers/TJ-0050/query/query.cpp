#include<bits/stdc++.h>
using namespace std;

#define ls p<<1
#define rs p<<1|1
const unsigned long long Q=46744073709551616;
int n,q;
long long a[50100],s[50100],tr[10100][10100];

void init()
{
	for(int k=1;k<=n;++k)
	{
		priority_queue<int> q;
		map<int,int> dict;
		
		for(int i=1;i<=n;++i)
		{
			if(i+k-1<=n)
			{
				dict[s[i+k-1]-s[i-1]]=i+k-1;
				q.push((s[i+k-1]-s[i-1]));
			}
			while(dict[q.top()]<i)q.pop();
			tr[i][k]=q.top();
		}
	}
}

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	
	scanf("%d",&q);
	
	init();
	
	while(q--)
	{
		int L,R;
		long long ans=0;
		scanf("%d %d",&L,&R);
		
		for(int i=1;i<=n;++i)
		{
			long long rc=-100000000;
			for(int k=L;k<=R;++k)
			{
				rc=max(rc,tr[i][k]);
			}
			ans^=(long long)i*rc;
		}
		
		if(ans>=0)printf("%lld\n",ans);
		else cout<<"184"<<((Q+ans))<<'\n';
	}
	return 0;
}

