#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=110000;
int n,m,x[N],y[N];
int max1=1e10;
int ans=0;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>x[i]>>y[i];
		max1=min(max1,x[i]+y[i]);
	}
	sort(x+1,x+n+1);
	int s=0;
	for(int i=0;i<=n;++i){
		s+=x[i];
		if(s>m)break;
		ans=max(ans,i+(m-s)/max1*2);
	}
	cout<<ans<<'\n';
	return 0;
}
