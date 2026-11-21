#include<bits/stdc++.h>
using namespace std;
const long long m=1e4+7;
long long qpow(long long a,long long b) {
	long long ans = 1;
	while(b){
		if(b&1)ans=ans*a%m;
		b>>=1;
		a=a*a%m;
	}
	return ans;
}
long long a[10005];
int main(){
	freopen("height.in","r",stdin);
	freopen("height.out","w",stdout);
	long long n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==2)cout<<qpow(a[1],a[2]);
	if(n==3)cout<<qpow(a[1],qpow(a[2],a[3]));
	return 0;
}
