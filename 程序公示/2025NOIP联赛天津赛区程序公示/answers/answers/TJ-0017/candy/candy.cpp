#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct candy{
	long long x,y,w;
	bool v;
}a[N];
bool cmp(candy x,candy y){
	return x.w>y.w;
}
bool cmp2(candy x,candy y){
	return x.x<y.x;
}
long long sum[N];
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].w=a[i].x+a[i].y;
	}
	sort(a+1,a+1+n,cmp);
	long long u=a[n].w;
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i].x;
	}
	long long ans=0;
	for(int i=0;i<=n;i++){
		long long t=i+int((m-sum[i])/u)*2;
		ans=max(ans,t);
	}
	cout<<ans<<endl;
	return 0;
}
