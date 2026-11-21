#include <bits/stdc++.h>
using namespace std;
long long n, m,f[100000005],g[100000005],p=20100403;
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
void init() {
	f[0]= g[0] = 1;
	for(int i=1; i<=n+n; i++) {
		f[i] = f[i-1]*i%p;
	} 
	
	g[n+n] = qpow(f[n+n], p-2, p); 
	for(int i=n+n-1; i>=1; i--) { 
		g[i] = g[i+1]*(i+1)%p;
	}
}
int  getC(int  n, int  m, int p) {
	if(n<m) return 0;
	
	return f[n]*g[n-m]%p*g[m]%p;
}
int main(){
    cin >> n;
    init();
    cout << (getC(2*n, n, p) - getC(2*n, n - 1, p)+p)%p;
    return 0;
}