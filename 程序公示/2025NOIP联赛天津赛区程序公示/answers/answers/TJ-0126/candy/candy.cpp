#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+25;

int n;
ll m;
ll w1[N],w2[N],w3[N];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>w1[i]>>w2[i];
		w3[i]=w1[i]+w2[i];
	}
	sort(w1+1,w1+n+1);
	sort(w3+1,w3+n+1);
	ll mn_xy=w3[1];
	ll ans=0;
	for (int i=0;i<=n;++i){
		m-=w1[i];
		if (m<0) break;
		ll now=m/mn_xy;
		now*=2;
		ans=max(ans,now+i);
	}
	cout<<ans;
	return 0;
}
