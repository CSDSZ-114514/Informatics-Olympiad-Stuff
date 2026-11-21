#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
const int N=1e5+10;
int c,T;
int n,m,a[N],ans,sum;
int C(int x,int y){
	if(x>y||x<0||y<0) return 0;
	if(x==0) return 1;
	int ret=1;
	for(int i=y;i>=(y-x+1);i--) ret*=i;
	for(int i=1;i<=x;i++) ret/=i;
	return ret;
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		ans=0;sum=1;
		for(int i=1;i<=n;i++) sum=sum*2%mod;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			for(int j=0;j<i;j++){
				int l=upper_bound(a+1,a+1+n,a[i]+a[j])-a;
				int r=lower_bound(a+1,a+1+n,a[i]*2)-a-1;
				if(l>r) continue;
				int x=l-1-i,y=r-l+1,z=n-r;
				for(int i=0;i<y;i++) ans=(ans+C(i,y)%mod*C(m-2-i-z,x+z)%mod)%mod;
			}
		}
		cout<<(sum+mod-ans)%mod<<endl;
	}
	return 0;
}
/*
0 1
5 5
48 33 25 24 24
*/
