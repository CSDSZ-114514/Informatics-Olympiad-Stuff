#include<bits/stdc++.h>
using namespace std;
long long n,p;
long long ksm(long long a,long long b,long long m){
	long long ans=1;
	if(m==0)return 0;
	while(b!=0){
		if(b%2==1){
			ans=ans*a%m;
		}
		b/=2;
		a=a*a%m;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cout<<ksm(i,p-2,p)<<'\n';
	}
}
