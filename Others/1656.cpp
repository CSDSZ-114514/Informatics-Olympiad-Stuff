#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long f[100005],g[100005];
long long qpow(long long a,long long b,long long p){
	long long ans=1;
	while(b>0){
		if(b%2==1){
			ans=ans*a%p;
		}
		b/=2;
		a=a*a%p;
	}	
	return ans;
}
void init(long long up,long long p){
	f[0]=g[0]=1;
	for(int i=1;i<=up;i++){
		f[i]=f[i-1]*i%p;
	}
//	g[up]=qpow(f[up],p-2,p);
//	for(int i=up-1;i>=1;i--){
//		g[i]=g[i+1]*(i+1)%p;
//	}
	
	for(int i=1;i<=up;i++){
		g[i]=qpow(f[i],p-2,p);
	}
}
long long getC(long long n,long long m,long long p){
	if(n>=m){
		return ((f[n]*g[m]%p)*(g[n-m]%p))%p;
	}else{
		return 0;
	}
}
long long lucas(long long n,long long m,long long p){
	if(m==0){
		return 1;
	}else{
		return lucas(n/p,m/p,p)*getC(n%p,m%p,p)%p;
	}
}
int main(){
	long long T=0;
	cin>>T;
	init(10007-1,10007);
	while(T--){
		cin>>n>>m;
		cout<<lucas(n,m,10007)<<endl;
	}
	
}
