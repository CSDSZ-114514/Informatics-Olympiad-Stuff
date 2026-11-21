#include<bits/stdc++.h>
using namespace std;
long long n,q,d[1000005],as[1000005],sumd[1000005];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>d[i];
	sort(d+1,d+1+n);
	for(int i=1;i<=n;i++)sumd[i]=sumd[i-1]+d[i];
	for(int i=1;i<=n;i++)as[i]=as[i-1]+sumd[i];
	for(int i=1;i<=q;i++){
		long long t;
		cin>>t;
		long long l=1,r=n,ans=0;
		while(l<=r){
			long long mid=(l+r)>>1;
			if(as[mid]<=t){
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
