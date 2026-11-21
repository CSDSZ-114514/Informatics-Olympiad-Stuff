#include<bits/stdc++.h>
using namespace std;
long long n,mxn[100005];
long long dep[1000005],def[1000005][25];
vector<long long> v[100005];
void dfs(long long u,long long fa){
	dep[u]=dep[fa]+1;
	def[u][0]=fa;
	for(int i=1;i<=20;i++){
		def[u][i]=def[def[u][i-1]][i-1];
	}
	mxn[u]=max(u,mxn[fa]);
	for(long long t:v[u]){
		dfs(t,u);
	}
}
long long lca(long long u,long long v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=20;i>=0;i--){
		if(dep[def[u][i]]>=dep[v]){
			u=def[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=20;i>=0;i--){
		if(def[u][i]!=def[v][i]){
			u=def[u][i];
			v=def[v][i];
		}
	}
	return def[u][0];
}
int main(){
	cin>>n;
	for(long long i=1;i<n;i++){
		long long a;
		cin>>a;
		v[a].push_back(i);
	}
	dfs(0,0);
	long long q;cin>>q;
	while(q--){
		long long m;cin>>m;
		long long a[100005];memset(a,0,sizeof(a));
		for(int i=1;i<=m;i++){
			cin>>a[i];
		}
		for(int i=2;i<=m;i++){
			a[i]=lca(a[i],a[i-1]);
		}
		cout<<mxn[a[m]]<<endl;
	}
	return 0;
}
