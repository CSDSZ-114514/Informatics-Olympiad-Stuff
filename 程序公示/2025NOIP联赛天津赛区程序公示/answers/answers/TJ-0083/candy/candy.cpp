#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ans,c,cnt,mi=9999999,dp[1000005];
struct candy{
	long long x,y,z;
}a[100005];
bool cmp(candy a,candy b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].z=a[i].x+a[i].y;
		if(mi>a[i].z) mi=a[i].z;
	}
	while(true){
		cnt++;
		if(m>=cnt*mi){
			dp[cnt]=2*cnt;
		}
		else break;
	}
	sort(a+1,a+n+1,cmp);
	int f=1;
	cnt--;
	ans=dp[cnt];
	while(sum<=m && f<=n){
		sum+=a[f].x;
		if(m>=cnt*mi+sum){
			ans=max(ans,dp[cnt]+f);
		}
		if(cnt==0) break;
		while(m<cnt*mi+sum){
			cnt--;
			if(cnt==0) break;
		}
		f++;
	}
	cout<<ans<<endl;
	return 0;
}
