#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,d=9e18,mx,sum;
struct candy{
	int x;
	int y;
} a[100005];
bool cmp(candy x,candy y){
	return x.x<y.x;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].x,&a[i].y);
		d=min(d,a[i].x+a[i].y);
	}
	sort(a+1,a+1+n,cmp);
	for (int i=0;i<=n;i++){
		sum+=a[i].x;
		if (sum>m) break;
		mx=max(mx,i+(m-sum)/d*2);
	}
	cout<<mx;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

