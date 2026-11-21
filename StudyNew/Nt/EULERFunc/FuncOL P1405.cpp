#include<bits/stdc++.h>
using namespace std;
long long n,a[100005];
const long long m=10007;
long long qpow(long long a, long long b, long long m) {
	long long ans = 1;
	while(b) {
		if(b%2==1) {
			ans = ans * a;
            if(ans>=m){
                ans=ans%m+m;
            }
		}
		b/=2;
		a= a*a;
        if(a>=m){
            a=a%m+m;
        }
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
    if(i==n+1){
        return 1;
    }
    return qpow(a[i],solve(i+1,getphi(m)),m);
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    cout<<solve(1,m)%m;
    return 0;
}