#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
ll n,p,ans=1;
bool a[N];
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1) res=res*a%p;
		b/=2;
		a=a*a%p;
	}
	return res;
}
ll check(ll x){
	ll res=0,y=x;
	while(y<=2*n){
		res+=2*n/y-n/y-(n+1)/y;
		y*=x;
	}
	return qpow(x,res);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>p;
	for(int i=2;i<=2*n;++i){
		if(!a[i]){
			ans=ans*check(i)%p;
			for(int j=2*i;j<=2*n;j+=i){
				a[j]=1;
			}
		}
	}
	cout<<ans;
	return 0;
}