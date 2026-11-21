#include<bits/stdc++.h>
#define LL long long
using namespace std;
long long n,m;
LL qpow(LL a,LL b,LL m){
	LL ans=1;
	while(b>0){
		if(b%2==1){
			ans=ans*a%m;
		}
		b/=2;
		a=a*a%m;
	}	
	return ans;
}
int main(){
	cin>>m>>n;
	int allin=qpow(m,n,100003);
	int allno=m%100003*qpow(m-1,n-1,100003)%100003;
	int ans=allin-allno;
	while(ans<0){
		ans+=100003;
	}
	cout<<ans;
	return 0;
}
