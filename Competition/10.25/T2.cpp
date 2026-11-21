#include<bits/stdc++.h>
using namespace std;
long long sub,T;
long long n;
const long long MAXN=100005;
const long long mod=998244353;
const __int128_t INF=(__int128_t)1e35;
vector<long long> e[MAXN];
long long a[MAXN],c[MAXN],p[MAXN];
long long dp[MAXN];
__int128_t rdp[MAXN];
void dfs(long long u,long long fa){
	long long cst=0,rsum=0;
	for(auto v:e[u]){
		if(v==fa)continue; 
		dfs(v,u);
		__int128_t x=(__int128_t)p[u]*rdp[v];
        if(x>INF)x=INF;
        long long mx=(__int128_t)p[u]*dp[v]%mod;
        __int128_t y=rdp[v]+a[v]+(__int128_t)(p[u]-1)*c[v]*p[v];
        if(y>INF)y=INF;
        long long my=(dp[v]+a[v]+(__int128_t)(p[u]-1)*c[v]%mod*p[v])%mod;
        if(x<y){
            cst=(cst+mx)%mod;
            rsum=min(rsum+x,INF);
        }else{
            cst=(cst+my)%mod;
            rsum=min(rsum+y,INF);
        }
	}
	dp[u]=((__int128_t)c[u]*p[u]+cst)% mod;
    rdp[u]=min((__int128_t)c[u]*p[u]+rsum,INF);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>sub>>T;
	while(T--){
		
		cin>>n;for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<n;i++){
			long long u,v;cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=1;i<=n;i++)cin>>a[i]>>c[i]>>p[i];
		dfs(1,0);
		cout<<dp[1]<<endl;
	}
	
	return 0;
} 
