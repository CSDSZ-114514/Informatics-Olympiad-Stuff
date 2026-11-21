#include<bits/stdc++.h>
using namespace std;
long long n;long long k,f[1000005][5];
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
	for(long long t:v[u]){
		if(fa!=t){
			dfs2(t,u);
			f[u][1]*=(f[t][2]%((long long)1e9+7)+f[t][3]%((long long)1e9+7))%((long long)1e9+7);f[u][1]=f[u][1]%((long long)1e9+7);
			f[u][2]*=(f[t][1]%((long long)1e9+7)+f[t][3]%((long long)1e9+7))%((long long)1e9+7);f[u][2]=f[u][2]%((long long)1e9+7);
			f[u][3]*=(f[t][2]%((long long)1e9+7)+f[t][1]%((long long)1e9+7))%((long long)1e9+7);f[u][3]=f[u][3]%((long long)1e9+7);
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		long long a,b;
		cin>>a>>b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			f[i][j]=1;
		}
	}
	for(int i=1;i<=k;i++){
		long long a,b;
		cin>>a>>b;
		if(b==1){
			f[a][2]=0;
			f[a][3]=0;
		}
		if(b==2){
			f[a][1]=0;
			f[a][3]=0;
		}
		if(b==3){
			f[a][1]=0;
			f[a][2]=0;
		}
	}
	dfs2(1,1);
	//cout<<f[1][1]<<"　"<<f[1][2]<<"　"<<f[1][3];
	cout<<(f[1][1]%((long long)1e9+7)+f[1][2]%((long long)1e9+7)+f[1][3]%((long long)1e9+7))%((long long)1e9+7);
	return 0;
}
