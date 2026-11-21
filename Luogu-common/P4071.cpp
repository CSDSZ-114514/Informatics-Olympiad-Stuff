#include<bits/stdc++.h>
using namespace std;
const long long p=(long long)1e9+7;
long long t,n,m,f[1000015],cf[1000015],cg[1000015];
long long qpow(long long a,long long b){
	long long ans=1;
	while(b>0){
		if(b%2==1){
			ans=ans*a%p;
		}
		b/=2;a=a*a%p;
	}
	return ans;
}
long long init(){
	f[1]=0;
	f[0]=0;
	f[2]=1;
	for(int i=3;i<=1000005;i++){
		f[i]=(f[i-1]+f[i-2])*(i-1)%p;
	}
	cf[0]=1;cg[0]=1;
	for(int i=1;i<=1000005;i++){
		cf[i]=(cf[i-1]*i)%p;
		cg[i]=qpow(cf[i],p-2);
	}
	return 1;
}
long long getc(long long cn,long long cm){
	return cf[cn]%p*cg[cn-cm]%p*cg[cm]%p;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;init();
	while(t--){
		cin>>n>>m;
		if(n==m){
			cout<<1<<"\n";
			continue;
		}
		cout<<getc(n,m)*f[n-m]%p<<"\n";
	}
	return 0;
}
