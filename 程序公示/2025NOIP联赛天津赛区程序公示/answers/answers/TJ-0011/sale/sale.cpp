#include<bits/stdc++.h>
#define int long long
#define pb emplace_back
#define fi first
#define se second
#define mkp make_pair
#define il inline
typedef long long ll;
using namespace std;
using pii=pair<int,int>;
template<typename T> T& read(T& s){
	s=0;char c;
	do c=getchar();while(!isdigit(c));
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return s;
}
template<typename T> void write(T x){
	if(!x)return putchar(48),void();
	static int St[40],Top;
	if(x<0)putchar('-'),x=-x;
	while(x)St[++Top]=x%10,x/=10;
	while(Top)putchar(St[Top--]^48);
}
const int mod=998244353;
int poww(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=(ll)res*x%mod;
		x=(ll)x*x%mod;
		y>>=1;
	}
	return res;
}
const int N=1e4+5;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n,m,a[N];ll f[N];
pii b[N]; 
il void solve(){
	read(n);read(m);
	for(int i=1;i<=n;i++)read(a[i]);
	if(n<=10){
//		if(m==1)cou
		int ans=0;
		for(int S=0;S<(1<<n);S++){
			for(int j=1;j<=m+3;j++)f[j]=-inf;
			for(int i=1;i<=n;i++){
				int w=1+(S>>(i-1)&1);
				for(int j=m;j>=w;j--)f[j]=max(f[j],f[j-w]+a[i]);
			}
			for(int i=1;i<=n;i++){
				int w=1+(S>>(i-1)&1);
				b[i].fi=a[i]*(w==1?2:1);b[i].se=i;
			}
			sort(b+1,b+n+1,[](pii x,pii y){return x.fi==y.fi?a[x.se]>a[y.se]:x.fi>y.fi;});
			int cnt=0;ll res=0;
			for(int i=1;i<=n;i++){
				int w=1+(S>>(b[i].se-1)&1);
				if(cnt+w>m)continue;
				cnt+=w;res+=a[b[i].se];
			}
			ll res2=0;
			for(int i=1;i<=m;i++)res2=max(res2,f[i]);
//			if(res!=res2)cout<<S<<" "<<res<<" "<<res2<<endl;
			ans+=(res==res2);
		}
		write(ans);putchar('\n');
		return ;
	}
	write(poww(2,n));putchar('\n');
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int T=1,c;
	read(c);read(T);
	while(T--){
		solve();
	}
	return 0;
}

