#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long qpow(long long a,long long b,long long m){
	long long ans=1;
	while(b>0){
		if(b%2==1){
			ans=ans*a%m;
		}
		b/=2;a=a*a%m;
	}
	return ans;
}
int main(){
	cin>>n>>k;
	cout<<qpow(qpow(2,k,998244353)-1,n,998244353);
	return 0;
}
