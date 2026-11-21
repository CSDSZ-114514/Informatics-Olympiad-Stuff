#include<bits/stdc++.h>
using namespace std;
int t;
int c;
long long n,m;
long long a[5010];
long long qpow(long long x,long long y){
	long long k=x;
	long long ans=1;
	while(y!=0){
		if(y%2==1) ans*=k;
		y/=2;
		k*=k;
		k%=998244353;
		ans%=998244353;
	}
	return ans;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		cout<<qpow(2,n);
	}
	return 0;
}
