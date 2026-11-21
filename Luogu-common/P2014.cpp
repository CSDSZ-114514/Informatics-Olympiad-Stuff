#include<bits/stdc++.h>
using namespace std;
long long n;long long m,s[1000005],rd[1000005],f[1005][1005];
long long dep[1000005],def[1000005][25];
vector<long long> v[100005];
void dfs(long long u,long long fa){
	dep[u]=dep[fa]+1;
	def[u][0]=fa;
	for(int i=1;i<=20;i++){
		def[u][i]=def[def[u][i-1]][i-1];
	}
	for(long long t:v[u]){
		if(fa!=t){
			dfs(t,u);
		}
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
void dfs2(long long u,long long fa){
	f[u][1]=s[u];
	
	for(long long t:v[u]){
		dfs2(t,u);
		for(int j=m;j>=1;j--){
			for(int k=0;k<=j-1;k++){
				f[u][j]=max(f[u][j-k]+f[t][k],f[u][j]);
			}
		}
	}
}
int main(){
	cin>>n>>m;m++;
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k>>s[i];
		v[k].push_back(i);
		rd[i]++;
	}

	dfs2(0,0);
	cout<<f[0][m];
	return 0;
}
