#include <bits/stdc++.h>
using namespace std;
vector<int> g[15];
int c[15];
int d[15][15];
long long sum[15];
void dfs(int u,int fa){
	d[u][c[u]]=1;
	for(int v:g[u]){
		if(v==fa) continue;
		dfs(v,u);
		for(int i=0;i<=12;i++){
			d[u][i]|=d[v][i];
		}
		sum[u]+=sum[v];
	}
	for(int i=0;i<12;i++){
		if(d[u][i]==0){
			sum[u]+=i;
			break;
		}
	}
	return;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		memset(c,0,sizeof c);
		int n,m;
		cin>>n>>m;
		for(int i=0;i<=7;i++){
			g[i].clear();
		}
		for(int i=2;i<=n;i++){
			int x;
			cin>>x;
			g[i].push_back(x);
			g[x].push_back(i);
		}
		long long ans=0;
		while(c[n+1]==0){
			memset(d,0,sizeof d);
			memset(sum,0,sizeof sum);
			dfs(1,1);
			ans=max(ans,sum[1]);
			c[1]++;
//			for(int i=1;i<=n;i++){
//				cout<<c[i]<<" ";
//			}
//			cout<<endl;
			for(int i=1;i<=12;i++){
				if(c[i]>=n){
					c[i+1]++;
					c[i]-=n;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
