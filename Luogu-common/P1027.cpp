#include<bits/stdc++.h>
using namespace std;
long long a0,a1,b0,b1,ans;
int main(){
	long long n;cin>>n;
	while(n--){
		ans=0;
		cin>>a0>>a1>>b0>>b1;
		//cout<<lcm(4,6);
		for(long long i=1;i<=sqrt(b1);i++){
			if(b1%i==0){
				if(__gcd(i,a0)==a1&&i*b0/__gcd(i,b0)==b1){
					ans++;
				}
				if(b1/i!=i&&__gcd(b1/i,a0)==a1&&b1/i*b0/__gcd(b1/i,b0)==b1){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
