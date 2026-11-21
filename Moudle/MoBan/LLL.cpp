#include <bits/stdc++.h>
#define ll long long
#define ld long double 
using namespace std;
const ll N = 5e5+5; 
const ll MOD = 1e9+7;
const ld INF = 1e18;   

  
ld df[N];    
ld psf[N];
ll llim,rlim; 
ll qpow(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b%2==1){
			ans=ans*a%MOD;
		}
		b/=2;
		a=a*a%MOD;
	}	
	return ans;
}
ll a[N],ps[N],dm[N];  


ld gtf(int j, int i) {
    ld ss = psf[i] - psf[j]; 
    
    ld kk = (ld)(i - j); 
    return (ss * ss) / (kk * kk);
}
ll gtm(int j, int i) { 
    ll ss = (ps[i] - ps[j] + MOD) % MOD; 
    ll k = i - j;
    ll k2 = k * k % MOD;
    ll iv = qpow(k2, MOD - 2); 
    return (ss * ss) % MOD * iv % MOD;
}
void cdq(int l, int r) { 
    if (l >= r) return;
    ll m = (l + r) >>1; 
    cdq(l, m);
    for (int i = m + 1; i <= r; ++i) {
        for (int j = l; j <= m; ++j) {
            ll k = i - j; 
            if (k < llim || k > rlim) continue; 
            if (df[j] < -0.5 * INF) continue; 

            ld bf = gtf(j, i); //this is the beauty of mathematic. by ZRC.
            ld cuf = df[j] + bf; 
            if (cuf > df[i]) {
                df[i] = cuf;
                ll bm = gtm(j, i);
                dm[i] = (dm[j] + bm) % MOD;
            }
        }
    }
    cdq(m + 1, r);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, q; 
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, greater<ll>());

    ps[0] = 0;
    psf[0] = 0;
    for (int i = 1; i <= n; i++) {
        ps[i] = (ps[i - 1] + a[i]) % MOD;
        psf[i] = psf[i-1] + (ld)a[i]; 
    }
    while (q--) {
        ll l, r; 
        cin>>l>>r;

        llim = l;
        rlim = r;
        memset(dm,0,sizeof(dm));
        for(int i=0;i<=n+1;i++){
            df[i]=-INF;
        }
        df[0] = 0.0;
        
        cdq(0, n);
        if (df[n] < -0.5 * INF) {
            cout << -1 << '\n'; 
        } else {
            cout << dm[n] << '\n';
        }
    }

    return 0;
}