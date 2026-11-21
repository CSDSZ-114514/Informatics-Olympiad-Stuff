#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e4;
int T;
ll cd[N],n,m,x,sum,a[N],cnt[N];
vector<int> e[N];
void dg(int u){
	for(int v:e[u]){
		if(cd[v]==0){
			a[v]=cnt[u]++;
			if(cnt[u]==1){
				sum++;
			}
		}else{
			dg(v);
		}
		a[u]=max(a[v]+1,a[u]);
	}
	sum+=a[u]+1;
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>m;
		memset(a,0,sizeof(a));
		memset(cnt,0,sizeof(cnt));
		memset(cd,0,sizeof(cd));
		memset(e,0,sizeof(e));
		sum=0;
		for(int i=2;i<=n;i++)
		{
			cin>>x;
			e[x].push_back(i);
			cd[x]++;
		}
		dg(1);
		cout<<sum<<"\n";
	}
	return 0;
}
