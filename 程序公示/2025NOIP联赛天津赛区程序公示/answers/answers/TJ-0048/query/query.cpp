#include<bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL N=3005;
LL MOD;
LL n;
LL a[N];
LL k[N];
LL sum[N];
LL ans;

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	MOD=pow(2,64);
	cin>>n;
	for(LL i=1;i<=n;i++) {
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	LL Q;
	cin>>Q;
	LL L,R;
	while(Q--){
		for(LL i=1;i<=n;i++) k[i]=-LLONG_MAX;
		ans=0;
		cin>>L>>R;
		for(LL i=1;i<=n;i++) {
			for(LL j=L;j<=R;j++) {
				for(LL l=max(i-j+1,1ll);l<=min(i,n-j+1);l++){
					LL r=l+j-1;
					k[i]=max(k[i],sum[r]-sum[l-1]);
				}
			}
		}
		for(LL i=1;i<=n;i++) {
			ans=ans^((i*k[i])%MOD);
		}
		cout<<ans<<endl;
	}
	return 0;
}
