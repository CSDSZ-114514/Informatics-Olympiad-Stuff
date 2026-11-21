#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+10;

int arr[N],sum[N],n,m,ans,pre;

signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>arr[i];
		cin>>x;
		sum[i]=arr[i]+x;
	}
	sort(sum+1,sum+1+n);
	sort(arr+1,arr+1+n);
	ans=((int)m/sum[1])*2;
	for(int i=1;i<=n;i++){
		pre+=arr[i];
		ans=max(ans,i+((int)(m-pre)/sum[1])*2); 
	}
	cout<<ans<<endl;
	
	return 0;
}
//!noip@Nov29,2025:dream
