#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b;
bool check(long long mid){
	if(a<b){
		return floor((1.0*m-1.0*a*mid)/(b-a))>=ceil((1.0*n-1.0*b*mid)/(a-b));
	}else if(b<a){
		return floor((1.0*n-1.0*b*mid)/(a-b))>=ceil((1.0*m-1.0*a*mid)/(b-a));
	}else{
		return (a+b)*mid<=n+m;
	}
}
int main(){
	freopen("prize.in","r",stdin);
	freopen("prize.out","w",stdout);
	cin>>n>>m>>a>>b;
	long long l=0,r=1e18,ans=10005;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
