#include<bits/stdc++.h>
#define int long long
using namespace std;
constexpr int N = 8005;
vector<int> E[N];
int t,n,m,fa[N];
unsigned long long dfs(int u,int len,int fa){
	unsigned long long ans=len,tmp;
	ans+=(unsigned long long)u<<32;
	for(auto v : E[u]){
		if(v==fa) continue;
		tmp=dfs(v,len+1,u);
		if((tmp&INT_MAX)>(ans&INT_MAX)){
			ans=tmp;
		}
	}
	return ans;
}
unsigned long long num(int p){
	unsigned long long ans=1,tmp;
	int maxx;
	for(auto v : E[p]){
		tmp=num(v);
		ans+=tmp&INT_MAX;
		maxx=maxx>tmp>>32?maxx:tmp>>32;
	}
	ans+=(ans&INT_MAX+maxx)<<32;
	return ans;
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) E[i].clear();
		for(int i=2;i<=n;i++){
			cin>>fa[i];
			E[fa[i]].emplace_back(i);
			E[i].emplace_back(fa[i]);
		}
		unsigned long long rt=dfs(1,1,-1)>>32;
		cout<<(num(rt)>>32)<<endl;
	}
	cout.flush();
	return 0;
}
