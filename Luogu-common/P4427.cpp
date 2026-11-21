#include<bits/stdc++.h>
using namespace std;
long long n,sum[1000005][55],k,fa[1000005];
long long dep[1000005],def[1000005][25];
vector<long long> v[1000005];
long long qpow(long long a,long long b,long long m){
	long long ans=1;
	while(b>0){
		if(b%2==1){
			ans=ans*a%m;
		}
		b/=2;
		a=a*a%m;
	}	
	return ans;
}
void dfs(long long u,long long fa){
	dep[u]=dep[fa]+1;
	//cout<<dep[u]<<" ";
	def[u][0]=fa;
	for(int i=1;i<=20;i++){
		def[u][i]=def[def[u][i-1]][i-1];
	}
	for(int i=1;i<=50;i++){
		sum[u][i]=(sum[fa][i]%998244353+qpow(dep[u],i,998244353))%998244353;
	}
	
	for(long long t:v[u]){
		if(t!=fa){
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
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		long long a,b;
		cin>>a>>b;
		v[a].push_back(b);v[b].push_back(a);
	}
	dep[1]--;
	dfs(1,1);
	//cout<<sum[2][5];
	long long m;cin>>m;
	while(m--){
		long long a,b;
		cin>>a>>b>>k;
		//cout<<endl<<sum[a][k]<<"　"<<sum[b][k]<<"　"<<sum[1][k]<<endl;
		cout<<(2*998244353+(sum[a][k]%998244353+sum[b][k]%998244353-sum[lca(a,b)][k]%998244353-sum[def[lca(a,b)][0]][k]%998244353))%998244353<<'\n';
	}
	return 0;
}
