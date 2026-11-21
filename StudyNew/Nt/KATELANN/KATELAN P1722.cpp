#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long n;
long long h[100005],f[100005],g[100005];
long long mod=1e9+7,p=1e9+7;
ll qpow(ll a, ll b, ll m) {
	ll ans = 1;
	while(b) {
		if(b%2==1) {
			ans = ans * a%m;
		}
		b/=2;
		a= a*a%m;
	}
	return ans;
}
void init() {
	f[0]= g[0] = 1;
	//递推求 f[i] 
	for(int i=1; i<=n; i++) {
		f[i] = f[i-1]*i%p;
        g[i]=qpow(f[i],p-2,p)%p;
	} 
}

int main(){
    cin>>n;
    long long zp=n;n=2*n;
    h[1]=1;
    h[0]=1;
    init();
    cout<<f[2*zp]%p*g[zp]%p*g[zp+1]%p;
}