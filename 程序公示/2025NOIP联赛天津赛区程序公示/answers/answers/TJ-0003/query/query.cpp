#include <bits/stdc++.h>
using namespace std;
int n,q;
long long a[50005];
struct node
{
	long long value,id;
	bool operator <(node other) const
	{
		return value<other.value;
	}
};
priority_queue<node> s;
long long t[3005][3005];
long long ans[10005];
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int len=1;len<=n;len++)
	{
		long long sum=0;
		for(int i=1;i<len;i++)
			sum+=a[i];
		for(int i=len;i<=n;i++)
		{
			sum-=a[i-len];
			sum+=a[i];
			t[len][i-len+1]=sum;
		}
	}
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int l,r;
		cin>>l>>r;
		memset(ans,-0x3f,sizeof(ans));
		for(int len=l;len<=r;len++)
		{
			while(!s.empty()) s.pop();
			for(int st=1;st<=n;st++)
			{
				while(!s.empty()&&s.top().id<=st-len) s.pop();
				if(st+len-1<=n)
					s.push(node{t[len][st],st});
				ans[st]=max(ans[st],s.top().value);
			}
		}
		unsigned long long sum=0;
		for(int i=1;i<=n;i++)
		{
			unsigned long long k=ans[i];
			sum^=k*i;
		}
		cout<<sum<<"\n";
	}
	return 0;
}
