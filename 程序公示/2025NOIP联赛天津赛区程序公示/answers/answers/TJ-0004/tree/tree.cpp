#include<bits/stdc++.h>
using namespace std;

namespace z {
const int N = 10 + 5, mod = 998244353;
#define int long long
int c[N],mx,ans,n,m;
vector<int> v[N],p[N];
int mex(vector<int>& vec){
	sort(vec.begin(),vec.end());
	int tar=0;
	for(int i:vec)if(i==tar)tar++;
	return tar;
}
void dfstree(int u) {
	v[u].push_back(c[u]);
	for(int ver:p[u]){
		dfstree(ver);
		for(int x:v[ver])v[u].push_back(x);
	}
	ans+=mex(v[u]);
}
void dfs(int step){
	if(step==n+1){
		ans=0;for(int i=1;i<=n;i++)v[i].clear();
		dfstree(1);
		mx=max(mx,ans);
		return;
	}
	for(int i=0;i<n;i++){
		c[step]=i;
		dfs(step+1);
	}
}
void solve(){
	ans=mx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i].clear();
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		p[x].push_back(i);
	}
	dfs(1);cout<<mx<<'\n';
}
void main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;cin>>T;
	while(T--)solve();

}

#undef int

}

int main() {
	z::main();
	return 0;
}
