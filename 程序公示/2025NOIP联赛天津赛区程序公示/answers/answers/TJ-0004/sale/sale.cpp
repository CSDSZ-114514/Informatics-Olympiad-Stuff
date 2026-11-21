#include<bits/stdc++.h>
using namespace std;

namespace z {
const int N = 5e5 + 5, mod = 998244353;
#define int long long
int a[N],fac[N],inv[N],pw[N];
int qpow(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}
int C(int n, int m){
	if(n<0||m<0||n<m)return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
void main() {
	fac[0]=pw[0]=inv[0]=1;
	for(int i=1;i<N;i++)fac[i]=fac[i-1]*i%mod,pw[i]=pw[i-1]*2%mod,inv[i]=qpow(fac[i],mod-2);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
		freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int Cid, T;cin>>Cid>>T;
	int cnt=0;
	while(T--){
//		cerr<<T<<'\n';
		int n, m; cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i],a[i]*=2;
		sort(a + 1, a + n + 1, greater<int>());
	//	for(int i = 1; i <= n; i++) cout << a[i] <<" \n"[i == n];
		int ans = qpow(2, n);

		for(int i = 1; i <= n; i++) {
			int l=n+1;
			for(int j = i+1;j<=n;j++) {
				//aj>ai/2
//				l=n+1;
				if(a[j]>a[i]/2) {
					//j是最后一个 枚举i+1到j-1还有几个在i后面的1
	//				cout<<a[i]<<" "<<a[j]<<" "<<a[n]+a[j]<<'\n';
	//				if(a[n]+a[j]>a[i])continue;
					l=max(l,j+1);
					while(l-1>j&&a[l-1]+a[j]<a[i])l--,cnt++;
//					cerr<<i<<" "<<j<<' '<<l<<'\n';
//					l=max(l,j+1);
	//				cout<<"??\n";
					int rem=max(0ll,j-1-(i+1)+1);
	//				cout<<i<<" "<<j<<" "<<l<<' '<<rem<<'\n';
					int tmp=C(rem+i-1,m-2-i+1);
					ans-=tmp*(pw[n-l+1]-(a[i]==a[j]))%mod;
//					for(int k=0;k<=rem;k++){
//						int tmp=C(rem,k)*C(i-1,m-2-k-(i-1))%mod*(qpow(2,n-l+1)-(a[i]==a[j]))%mod;
//	//					if(i==1&&j==3)cerr<<i<<' '<<j<<' '<<k<<" "<<tmp<<'\n';
//	//					if(tmp)cout<<i<<' '<<j<<' '<<k<<" "<<tmp<<'\n';
//						ans-=tmp;
//					}
				}
			}

		}

		cout << (ans%mod+mod)%mod << '\n';
	}
	//cerr<<cnt<<'\n';
}

#undef int

}

int main() {
	z::main();
	return 0;
}


