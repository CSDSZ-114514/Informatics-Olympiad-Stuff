#include<bits/stdc++.h>
using namespace std;
long long a,b;
long long qpow(long long a,long long b,long long m){
    long long ans = 1;
	while(b) {
		if(b%2==1) {
			ans = ans * a%m;
		}
		b/=2;
		a= a*a%m;
	}
	return ans;
}
long long getphi(long long n){
    long long res=n;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0){
            res=res/i*(i-1);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        res=res/n*(n-1);
    }
    return res;
}
int main(){
    cin>>a>>b;
    cout<<qpow(a,b-1,998244353)*getphi(a)%998244353;
    return 0;
}