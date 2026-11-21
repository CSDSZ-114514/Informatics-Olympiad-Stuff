#include<bits/stdc++.h>
using namespace std;
string b;
long long qpow(long long a, long long b, long long m) {
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
long long depow(long long phi){
    long long bx=0;
    for(int i=0;i<b.size();i++){
        bx=bx*10+(b[i]-'0');
        if(bx>=phi){
            bx%=phi;
            bx+=phi;
        }
    }
    return bx;
}
int main(){
    long long a,m;
    cin>>a>>m>>b;
    long long phi=getphi(m);
    long long bp=depow(phi);
    cout<<qpow(a,bp,m);
    return 0;
}