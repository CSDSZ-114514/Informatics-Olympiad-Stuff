#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,ans,lft;
ll cdy[100005];
ll am=2000000001;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		ll x,y;
		cin>>x>>y;
		cdy[i]=x;
		am=min(am,x+y);
	}
	sort(cdy+1,cdy+n+1);
	ans=(m/am)*2;
	lft=m%am;
	ll now=1;
	ll ansnow=ans;
	ll lftnow=lft;
	while(lft>=cdy[now]){
		lft-=cdy[now];
		++ans;
		++now;
	}
	now=1;
	while(ansnow>=2&&lftnow<=m){
		ansnow-=2;
		lftnow+=am;
		while(lftnow>=cdy[now]){
			lftnow-=cdy[now];
			++ansnow;
			if(now<n) ++now;
			else break;
		}
		if(ansnow>ans) ans=ansnow;
		else break;
	}
	cout<<ans;
	return 0;
}
