#include<bits/stdc++.h>
using namespace std;
#define ll long long
const long long p=1e9+7;
long long n,l[1000005],num[1000005],mxl=-1e9,ans;
long long f[100005],g[1000005];
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
	} 
	
	g[n] = qpow(f[n], p-2, p); //费马小定理 
	for(int i=n-1; i>=1; i--) { //逆向递推求g[x] 
		g[i] = g[i+1]*(i+1)%p;
	}
}
int  getC(int  n, int  m, int p) {
	if(n<m) return 0;
	
	return f[n]*g[n-m]%p*g[m]%p;
}
int main(){
	freopen("stick.in","r",stdin);
    freopen("stick.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>l[i];num[l[i]]++;mxl=max(mxl,l[i]);
    }
    init();
    for(int i=1;i<=mxl;i++){
        if(num[i]>=2){
            for(int j=1;j<=i/2;j++){
                if(j=i-j){
                    ans+=((getC(num[i],2,p))*(getC(num[j],2,p)));
                }
                if(j!=i-j){
                    ans+=((getC(num[i],2,p))*(getC(num[j],1,p))*(getC(num[i-j],1,p)));
                }
            }
        }
    }
    cout<<ans%p;
}