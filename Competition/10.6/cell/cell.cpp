#include<bits/stdc++.h>
using namespace std;
long long n,fa[100005],dep[100005],ans;
bool vis[100005]; 
struct PT{
	long long dpt,id;
	bool operator<(const PT p)const{
		if(dpt==p.dpt)return id<p.id;
		return dpt<p.dpt;
	}	
};
set<PT> s;
vector<long long> e[100005];
void dfs(long long u){
	dep[u]=dep[fa[u]]+1;
	s.insert({dep[u],u});
	for(auto v:e[u]){
		if(v==fa[u])continue;
		if(fa[v])continue;
		fa[v]=u;
		dfs(v);
	}
	return ;
} 
int main(){
	freopen("cell.in","r",stdin);
	freopen("cell.out","w",stdout);
	cin>>n;
	for(int i=1;i<n;i++){
		long long x,y;
		cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	e[0].push_back(1);
	dfs(1);
	while(!s.empty()){
		auto it=s.end();
		it--;
		vis[fa[(*it).id]]=true;ans++;
		s.erase({dep[fa[(*it).id]],fa[(*it).id]});
		for(auto t:e[fa[(*it).id]]){
			if(vis[t])continue;
			s.erase({dep[t],t});
			vis[t]=true;
		}
	}
	cout<<ans; 
	return 0;
}
