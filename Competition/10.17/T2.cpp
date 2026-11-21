#include<bits/stdc++.h>
using namespace std;
long long k,n,l,cm=0,co=0,f[1000005],g[1000005];
string T;
const long long MOD=1e9+7;
long long qpow(long long a,long long e){
    long long r=1;
    while(e){
        if(e&1)r=r*a%MOD;
        a=a*a%MOD;
        e>>=1;
    }
    return r;
}
long long C(long long n,long long k) {
    if (n<k)return 0;
    return f[n]*g[k]%MOD*g[n-k]%MOD;
}

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>k>>n>>l;
    cin>>T;
    for(char c:T){
        if(c=='M')++cm;
        else ++co;
    }
    if(co!=cm*k){
        cout<<0;
        return 0;
    }
    f[0]=g[0]=1;
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]*i%MOD;
	} 
	g[n]=qpow(f[n],MOD-2);
	for(int i=n-1;i>=1;i--){
		g[i]=g[i+1]*(i+1)%MOD;
	}
	long long p= 1;
    long long r=0,ob=0;

    for(char c:T) {
        if(c=='O'){
            ++ob;
        }else{
            ++r;
            int n=r*k-ob;
            p=p*C(n,k)%MOD;
        }
    }
    long long ans=qpow(p,l);
    cout <<ans;
} 
