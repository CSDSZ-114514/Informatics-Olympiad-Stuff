#include<bits/stdc++.h>
using namespace std;
long long T;
struct XZ{
	long long c,d;
	bool operator<(const XZ p)const{
		return c<p.c;
	}
}xz[10000005];
const long long mod=1e9+7;
long long qpow(long long a,long long b){
	long long ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod; 
		}
		a=a*a%mod;
		b>>=1; 
	}
	return ans;
}

int main(){
	cin>>T;
	while(T--){
		long long ans=1;
		long long n,m,v;
		cin>>n>>m>>v;
		for(int i=1;i<=m;i++){
			cin>>xz[i].c;
			cin>>xz[i].d;
		}
		sort(xz+1,xz+1+m);
		for(int i=2;i<=m;i++){
			long long x=xz[i].c-xz[i-1].c;
			if(x==0){
				if(xz[i].d==xz[i-1].d)continue;
				else goto abc;
			}
			ans=ans*(qpow(v,2*x)-qpow(v,x)+qpow(v,x-1)+mod*20)%mod;
		}
		ans=ans*qpow(v,2*(xz[1].c-1))%mod;
		ans=ans*qpow(v,2*(n-xz[m].c))%mod;
		cout<<ans<<endl;
		continue;
		abc:
		cout<<0<<endl;
		continue;
	}
	
	return 0;
} 