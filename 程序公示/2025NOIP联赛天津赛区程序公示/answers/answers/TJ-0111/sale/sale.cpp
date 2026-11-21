#include<bits/stdc++.h>
using namespace std;
const long long P=998244353;
long long a[6005],fac[6005],inv[6005],pw[6005];
bool cmp(long long x,long long y){
	return x>y;
}
void init(){
	fac[0]=fac[1]=inv[0]=inv[1]=pw[0]=1;
	pw[1]=2;
	for(long long i=2;i<=5002;i++){
		fac[i]=fac[i-1]*i%P;
		inv[i]=inv[P%i]*(P-P/i)%P;
		pw[i]=pw[i-1]*2%P;
	}
	for(long long i=2;i<=5002;i++){
		inv[i]=inv[i-1]*inv[i]%P;
	}
}
long long C(long long x,long long y){
	if(x<0||y<0) return 0;
	if(x<y) return 0;
	return fac[x]*inv[x-y]%P*inv[y]%P;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	long long cID,t;
	cin>>cID>>t;
	init();
	while(t--){
		long long n,m;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1,cmp);
		long long ans=0;
		for(long long x=1;x<=n;x++){
			long long j=n+1;
			for(long long i=x+1;i<=n;i++){
				if(a[i]*2>a[x]){
					while(j>=1&&a[i]+a[j]<a[x]){
						j--;
					}
					if(j!=n+1){
						ans+=C((x-1)+(i-x-1),m-2-(x-1))*pw[n+1-max(i+1,j+1)]%P;
						if(ans>=P) ans-=P;
					}
				}
			}
		}
		long long res=pw[n]-ans+P;
		if(res>=P) res-=P;
		cout<<res<<"\n";
		for(long long i=1;i<=n;i++){
			a[i]=0;
		}
	}
	return 0;
}
