#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define RLL register LL
#define PLL pair<LL,LL>
#define mp make_pair
#define mod 998244353
#define mo(x) ((x%mod+mod)%mod)
#define inf 0x3f3f3f3f3f3f3f3f
const LL N=5e3+10;
LL a[N],n,m,ans;

struct NODE{
	LL w,v;
	inline bool operator < (const NODE &nx) const{
		if(v*nx.w!=w*nx.v){
			return v*nx.w>w*nx.v;
		}
		return w>nx.w;
	}
} abc[20];
bool choose[20];

void dfs(LL st){
	if(st>n){
		for(RLL i=1;i<=n;++i){
			if(choose[i]){
				abc[i].w=1;
			}else{
				abc[i].w=2;
			}
			abc[i].v=a[i];
		}
		sort(abc+1,abc+n+1);
		LL nm=m,x=0,minx[3]={inf,inf,inf},maxx=-inf;
		for(RLL i=1;i<=n;++i){
			if(nm>=abc[i].w){
				nm-=abc[i].w;
				x+=abc[i].v;
				if(abc[i].w==1){
					minx[2]=abc[i].v;
					sort(minx,minx+3);
				}
			}else if(abc[i].w==2){
				maxx=max(maxx,abc[i].v);
			}
		}
		if(nm==1){
			ans=mo(ans+(minx[0]>=maxx?1ll:0ll));
		}else{
			ans=mo(ans+(minx[0]+minx[1]>=maxx?1ll:0ll));
		}
		return;
	}
	choose[st]=true;
	dfs(st+1);
	choose[st]=false;
	dfs(st+1);
	return;
}

inline LL qpow(LL a,LL x){
	LL ans=1;
	while(x){
		if(x&1){
			ans=mo(ans*a);
		}
		a=mo(a*a);
		x>>=1;
	}
	return ans;
}

inline void work(){
	cin>>n>>m;
	bool flag=true;
	for(RLL i=1;i<=n;++i){
		cin>>a[i];
		if(i>1 && a[i]!=a[i-1]){
			flag=false;
		}
	}
	if(flag || m+1>=(n<<1)){
		cout<<qpow(2ll,n)<<'\n';
		return;
	}
	sort(a+1,a+n+1);
	ans=0;
	if(m==2){
		for(RLL i=1;i<n;++i){
			if(a[i]==a[n]){
				break;
			}
			if((a[i]<<1)<=a[n]){
				ans=mo(ans+qpow(2ll,i-1));
			}
			for(RLL j=i+1;j<n;++j){
				if(a[j]==a[n]){
					break;
				}
				if(a[i]+a[j]>=a[n] && (a[j]<<1)>a[n]){
					ans=mo(ans+qpow(2ll,i-1));
				}
			}
		}
		for(RLL i=n;;--i){
			if(a[i]!=a[n]){
				break;
			}
			ans=mo(ans+qpow(2ll,i-1));
		}
		cout<<mo(ans+1)<<'\n';
		return;
	}
	dfs(1);
	cout<<ans<<'\n';
	return;
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	LL T;
	cin>>T>>T;
	while(T--){
		work();
	}
	return 0;
}
