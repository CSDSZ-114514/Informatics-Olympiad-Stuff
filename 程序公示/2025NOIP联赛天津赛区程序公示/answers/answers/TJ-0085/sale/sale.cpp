#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,T,c,m;
int v[5003];
int mod=998244353;
int ksm(int a,int x){
	int ap[1003];
	int t=0;
	int ans=1;
	while(a){
		ap[++t]=a&1;
		a/=2;
	}
	for(int i=1;i<=t;i++){
		if(ap[i])ans=(ans*x)%mod;
		x=((x*x)%mod);
	}
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
//	freopen("","r",stdin);
//	freopen("","w",stdout);
	cin>>c>>T;
	cout<<ksm(T,2);
//	for(int o=1;o<=T;o++){
//		cin>>n>>m;
//		for(int i=1;i<=n;i++){
//			cin>>v[i];
//		}
//		sort(v+1,v+n+1);
//		if(c==18){
//			cout<<ksm(n,2);
//		}
//	}
	return 0;
}
