#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[100005];
long long mod=998244353;
int main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdin);
	cin>>c>>t;
	for(int z=1;z<=t;z++) {
		long long ans=0;
		memset(a,0,sizeof(a));
		cin>>n>>m;
		for(int i=1;i<=n;i++) {
			cin>>a[i];
		}
		ans=1;
		for(int i=1;i<=n;i++) {
			ans=(ans*2)%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
