#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long mod=1e9+7;
long long a[100005];
long long qpow(long long a,long long b){
	long long ans=1;
	while(b) {
		if(b%2==1) {ans=ans*a%mod;}
		b>>=1;a=a*a%mod;
	}
	return ans;
}
long long f[100005],g[100005];
void init(){
	f[0]=g[0]=1;
	
	for(int i=1;i<=2000;i++) {
		f[i]=f[i-1]*i%mod;
	} 
	g[2000]=qpow(f[2000],mod-2);
	for(int i=2000-1;i>=1;i--) { 
		g[i]=g[i+1]*(i+1)%mod;
	}
}
long long combo(long long n,long long m) {
	if(n<m) return 0;
	return f[n]*g[n-m]%mod*g[m]%mod;
}
long long ans=0;
int main(){
	freopen("spec.in","read",stdin);
	freopen("spec.out","write",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)cin>>a[i];
	init();
	for(int k=0;k<=n;k++){
		long long res=1;
		for(int i=1;i<=m;i++){
			res=res*combo(n-k+a[i]-1,n-k-1)%mod;
		}
		res=res*combo(n,k)%mod;
		if(k&1)ans=(ans-res)%mod;
		else ans=(ans+res)%mod;
	}
	cout<<(ans%mod+mod)%mod;
	return 0;
}
