#include<bits/stdc++.h>
using namespace std;
long long f[100005],ans,n;
bool isbl[100005];
vector<long long> e[100005];
void dfs(int u, int father) {
	long long  m1=0,m2=0;
	for(int v:e[u]){
		if(v!=father){
			dfs(v,u);
			if(isbl[u]!=isbl[v]){
				if(f[v]>m1){
					m2=m1;
					m1=f[v];
				}else if(f[v]>m2){
					m2=f[v];
				}
			}
			
		}
	}
	f[u]=m1+1;
	ans = max(ans, m1+m2+1);
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>isbl[i];
	}
	for(int i=1;i<=n-1;i++){
		long long a,b;cin>>a>>b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	dfs(1,0);
	cout<<ans;
	return 0;
}
