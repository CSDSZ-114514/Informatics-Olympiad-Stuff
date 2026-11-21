#include<bits/stdc++.h>
using namespace std;
constexpr int N = 8e3+1;
int t,n,m,p[N],a[N],mex[N],ans = 0;
namespace Graph{
	int tot = 0,head[N],nxt[N<<1],to[N<<1];
	inline void connect_head(const int &u,const int &v){
		++tot;
		nxt[tot] = head[u];
		head[u] = tot;
		to[tot] = v;
	}
}using namespace Graph;
int cnt = 0;
vector<int>merge(const vector<int>&x,const vector<int>&y){
	vector<int>res;
	int id1 = 0,id2 = 0;
	while(id1<x.size()&&id2<y.size()){
		if(x[id1]<=y[id2]){
			res.push_back(x[id1++]);
		}else{
			res.push_back(y[id2++]);
		}
	}
	while(id1<x.size()){
		res.push_back(x[id1++]);
	}
	while(id2<y.size()){
		res.push_back(y[id2++]);
	}
	return res;
}
vector<int>solve(const int &u,const int &fa){
	vector<int>vec;
	vec.push_back(a[u]);
	for(int i = head[u];i;i = nxt[i]){
		int v = to[i];
		if(v!=fa){
			vector<int>ve = solve(v,u);
			vec = merge(vec,ve);
		}
	}
	unique(vec.begin(),vec.end());
	int res = -1;
	for(int i = 0;i<vec.size();++i){
		if(i!=vec[i]){
			res = i;
			break;
		}
	}
	if(res == -1){
		res = vec.size();
	}
	mex[u] = res;
	return vec;
}
void dfs(const int &x){
	if(x == n+1){
		for(int i = 1;i<=n;++i){
			mex[i] = 0;
		}
		solve(1,0);
		int now = 0;
		for(int i = 1;i<=n;++i){
			now+=mex[i];
		}
		ans = max(ans,now);
		return;
	}
	for(int i = 0;i<n;++i){
		a[x] = i;
		dfs(x+1);
	}
}
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 1;i<=n;++i){
			head[i] = nxt[i] = to[i] = a[i] = 0;
		}
		for(int i = n+1;i<=(n-1<<1);++i){
			nxt[i] = to[i] = 0;
		}
		tot = 0;
		for(int i = 2;i<=n;++i){
			cin >> p[i];
			connect_head(i,p[i]);
			connect_head(p[i],i);
		}
		ans = 0;
		dfs(1);
		cout << ans << '\n';
	}
	return 0;
}
