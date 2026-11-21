#include<bits/stdc++.h>
using namespace std;
long long n,a[4000005],b[4000005],mxa[4000005];
bool check(long long x){
	long long co=0;
	long long mn=0;
	for(int i=1;i<=n;i++){
		mn+=b[i];
		if(a[i]==mxa[i]){
			co=co+mn*a[i];
			mn=0;
		}
		if(co>=x){
			co-=x;
			continue;
		}
		long long les=x-co;
		if(a[i]==mxa[i]){
			co=co+mn*a[i];
			mn=0;
			if(co>=x){
				co-=x;
			}else{
				return false;
			}
		}else{
			long long cst=(les+a[i]-1)/a[i];
			if(mn>=cst){
				mn-=cst;
				co+=cst*a[i];
				co-=x;
			}else{
				return false;
			}
		}
	}
	return true;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	long long T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		for(int i=1;i<=n+2;i++)mxa[i]=-1e18;
		for(int i=n;i>=1;i--)mxa[i]=max(a[i],mxa[i+1]);
		long long l=1,r=1e18,ans=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(check(mid)){
				l=mid+1;
				ans=mid;
			}else{
				r=mid-1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
