#include<bits/stdc++.h>
using namespace std;
long long n,m,kk;
long long v[1000005]; 
long long f[105][40][40][25];
long long c[105][105];
const long long mod=998244353;
long long vpt[105][40];
void init(){
	for(int i=0;i<=n;i++){
		c[i][0]=c[i][i]=1;
	}
	for(int i=1;i<=30;i++){
		for(int j=1; j<i;j++){
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
		}
	}
}
long long x0cnt(long long x){
	long long res=0;
	while(x){
		res+= x&1;
		x>>=1;
	}
	return res;
}
int main(){
	cin>>n>>m>>kk;
	for(int i=0;i<=m;i++){
		cin>>v[i];
		vpt[i][0]=1;
		for(int j=1;j<=n;j++){
			vpt[i][j]=(vpt[i][j-1]*v[i])%mod;
		}
	}
	init();
	f[0][0][0][0]=1;
	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=kk;k++){
				for(int p=0;p<=n>>1;p++){
					for(int t=0;t<=n-j;t++){
						f[i+1][j+t][k+(t+p&1)][t+p>>1]=(f[i+1][j+t][k+(t+p&1)][t+p>>1]+f[i][j][k][p]*vpt[i][t]%mod*c[n-j][t]%mod)% mod ;
					}
				}
			}
		}
	}
	long long ans=0;
	for(int k=0;k<=kk;k++){
		for(int p=0;p<=n>>1;p++){
			if(k+x0cnt(p)<=kk)ans=(ans+f[m+1][n][k][p])%mod;
		}
	}
	cout<<ans;
	return 0;
}
