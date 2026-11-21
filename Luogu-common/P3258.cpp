#include<bits/stdc++.h>
using namespace std;
long long n;long long a[1000005],d[1000005];
long long dep[1000005],def[1000005][25];
vector<long long> v[1000005];
void dfs(long long u,long long fa){
	dep[u]=dep[fa]+1;
	def[u][0]=fa;
	for(int i=1;i<=24;i++){
		def[u][i]=def[def[u][i-1]][i-1];
	}
	for(long long t:v[u]){
		if(fa!=t){
			dfs(t,u);
		}
	}
}
void dfs2(long long u,long long fa){
	
	for(long long t:v[u]){
		if(fa!=t){
			dfs2(t,u);
			d[u]+=d[t];
		}
	}
}
long long lca(long long u,long long v){
	if(dep[u]<dep[v]){
		swap(u,v);
	}
	for(int i=24;i>=0;i--){
		if(dep[def[u][i]]>=dep[v]){
			u=def[u][i];
		}
	}
	if(u==v){
		return u;
	}
	for(int i=24;i>=0;i--){
		if(def[u][i]!=def[v][i]){
			u=def[u][i];
			v=def[v][i];
		}
	}
	return def[u][0];
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int i=1;i<n;i++){
		long long b,c;cin>>b>>c;
		v[b].push_back(c);
		v[c].push_back(b);
	}//cout<<1;
	dfs(1,1);//cout<<1;
	for(int i=1;i<n;i++){
		long long b=a[i],c=a[i+1],k=lca(a[i],a[i+1]);
		d[b]++;d[c]++;d[k]--;d[def[k][0]]--;
	}

	dfs2(1,1);
		//cout<<d[1]<<endl;
	for(int i=2;i<=n;i++){
		d[a[i]]--;
	}

	for(int i=1;i<=n;i++){
		cout<<d[i]<<endl;
	}
	return 0;
}
