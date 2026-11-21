#include<bits/stdc++.h>
using namespace std;
const int NR=8e3+10;
const int MR=1e1+10;
int in[NR],abb[NR];
int g[NR];
int val[NR];
bool box[NR][NR];
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		memset(g,0,sizeof(g));
		memset(in,0,sizeof(in));
		memset(abb,0,sizeof(abb));
		memset(val,0,sizeof(val));
		for(int i=2;i<=n;i++)
		{
			int x;
			cin>>x;
			in[x]++;
			abb[x]++;
			g[i]=x;
		}
		queue<int>q;
		for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
		while(!q.empty())
		{
			int tp=q.front();
			q.pop();
			val[tp]=max(val[g[tp]],val[tp]);
			val[g[tp]]=max(val[g[tp]],val[tp]+1);
			in[g[tp]]--;
			if(in[g[tp]]==0) q.push(g[tp]);
		}
		for(int i=1;i<=n;i++) if(!abb[i]) q.push(i);
		int ans=0,maxn=-1;
		for(int i=1;i<=n;i++) maxn=max(maxn,val[i]);
		maxn+=2;
		while(!q.empty())
		{
			int tp=q.front();
			q.pop();
			box[tp][val[tp]]=1;
			for(int i=0;i<=maxn;i++)
			{
				if(box[tp][i]==0)
				{
					ans+=i;
					break;
				}
			}
			for(int i=0;i<=maxn;i++)
			{
				if(box[tp][i]==1) box[g[tp]][i]=1;
			}
			abb[g[tp]]--;
			if(abb[g[tp]]==0) q.push(g[tp]);
		}
		cout<<ans<<"\n";
	}
	

	return 0;
}


