#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=3300;
int n,a[N],s[N];
int q,L,R;

signed main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
	}
	cin>>q;
	while(q--){
		cin>>L>>R;
		unsigned long long ans=0;
		unsigned long long max1=(1ull<<63);
		max1=max1+max1-1;
		for(int i=1;i<=n;++i){
			int ANS=-1e18;
			for(int j=max(1ll,i-R+1);j<=i;++j){
				for(int k=i;k<=min(n,i+R-1);++k){
					if(k-j+1>=L and k-j+1<=R){
						ANS=max(ANS,s[k]-s[j-1]);
					}
				}
			}
			unsigned long long max2=0;
			if(ANS<0)max2=max1+ANS+1;
			else max2=ANS;
			ans=ans^1ull*i*max2;
		} 
		cout<<ans<<'\n';
	}	
	return 0;
} 
