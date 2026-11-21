#include<bits/stdc++.h>
using namespace std;
long long n,a[100005];
long long m;
long long qpow(long long a, long long b, long long m) {
	long long ans = 1;
	while(b) {
		if(b%2==1) {
			ans = ans * a;
            ans=ans%m+m;
		}
		b/=2;
		a= a*a;
        a=a%m+m;
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
long long solve(long long i,long long m){
    if(m==1){
        return 1;
    }
    return qpow(2,solve(i+1,getphi(m)),m);
}
int main(){
    long long T;
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>m;
        cout<<solve(1,m)%m<<endl;
    }
    return 0;
}