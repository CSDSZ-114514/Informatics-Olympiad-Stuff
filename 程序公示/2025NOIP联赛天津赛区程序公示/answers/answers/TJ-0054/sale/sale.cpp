#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
#include<cassert>
template<typename T> bool tense(T &a,const T &b){return b<a?(a=b,true):false;}
template<typename T> bool relax(T &a,const T &b){return b>a?(a=b,true):false;}

int n,m;
const int mod = 998244353;
const int N = 50010;
int a[N];

namespace Force{
	
	struct Candy{
		int o,w,v,id;
		friend bool operator<(const Candy &a,const Candy &b){
			if(a.v!=b.v) return a.v>b.v;
			if(a.o!=b.o) return a.o>b.o;
			return a.id<b.id;
		}
	} b[N];
	
	void solve(){
		int ans = 0;
		for(int s=0;s<(1<<n);s++){
			for(int i=1;i<=n;i++) b[i] = {a[i],(s>>(i-1)&1)+1,2*a[i]/((s>>(i-1)&1)+1),i};
			std::sort(b+1,b+n+1);
//			for(int i=1;i<=n;i++) printf("%d%c",b[i].v," \n"[i==n]);
			int now = m;
			long long res = 0;
			for(int i=1;i<=n;i++) if(now>=b[i].w) now-=b[i].w,res+=b[i].o;
			int res2 = 0;
			for(int s1=0;s1<(1<<n);s1++){
				int cost = 0,sum = 0;
				for(int i=1;i<=n;i++) if(s1>>(i-1)&1) cost+=b[i].w,sum+=b[i].o;
				if(cost<=m) relax(res2,sum);
			}
			if(res==res2) ans=(ans+1)%mod;
		}
		printf("%d\n",ans);
	}
}

void solve(int c){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=10) Force::solve();
	else if(m==2*n-1){
		int res = 1;
		for(int i=1;i<=n;i++) res=(2ll*res)%mod;
		printf("%d\n",res);
		return;
	} else if(m==2*n-2){
		int res = 1;
		for(int i=1;i<=n;i++) res=(2ll*res)%mod;
		std::sort(a+1,a+n+1);
		for(int j=1;j<=n;j++){
			int low = j>1 ? 1 : 2;
			int chosen = a[j];
			if(a[low]>=2*a[j]) chosen = a[low];
			if(chosen!=std::max(a[low]/2,a[j])) res=(res-1+mod)%mod;
		}
		printf("%d\n",res);
	}
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) solve(c);
	return 0;
}

 
