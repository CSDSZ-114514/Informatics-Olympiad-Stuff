#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 10004 // 1e4
#define N 12
const int inf=1e18+7,mod=998244353;
int T,ccc,n,m,p2[M],a[M],ans,b[M];
int d[M];
std::pair<int,int>c[N];
inline int qpow(int b,int y,int r=1) {
	for(;y;y/=2,b=b*b%mod) if(y&1) r=r*b%mod;
	return r;
}
void dfs1(int x=0) {
	if(x==n) {
		for(int i=1;i<=n;i++) c[i]=std::make_pair(a[i]*(b[i]==1?2:1),b[i]),d[i]=0;
		std::sort(c+1,c+n+1); int cst=m,vk=-1,fg=0,cnt=0;
		// for(int i=1;i<=n;i++) std::cout<<c[i].first<<'-'<<c[i].second<<"  "; std::cout<<'\n';
		for(int i=n;i>=1;i--) if(cst>=c[i].second) d[i]=1,cst-=c[i].second; else if(c[i].second==2) vk=std::max(vk,c[i].first);
		int lim=(cst==1?1:2);
		vk*=2;
		for(int i=1;i<=n;i++) if(d[i]==1&&c[i].second==1&&cnt<lim) vk-=c[i].first,cnt++;
		if(vk>0&&cnt==lim) ans++;
		// std::cout<<cst<<' '<<cnt<<' '<<vk<<'\n';
		return ;
	}
	b[x+1]=1,dfs1(x+1),b[x+1]=2,dfs1(x+1);
}
signed main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>ccc>>T,p2[0]=1;
	for(int i=1;i<M;i++) p2[i]=p2[i-1]*2%mod;
	while(T--) {
		std::cin>>n>>m,ans=0;
		for(int i=1;i<=n;i++) std::cin>>a[i];
		if(ccc<=5) {
			dfs1();
			std::cout<<(p2[n]-ans%mod+mod)%mod<<'\n';
		} else if(m==2) {
			std::sort(a+1,a+n+1);
			for(int i=n;i>=2;i--) {
				for(int j=i-1;j>=1;j--) {
					int A=a[i],B=a[j],C=(i!=n?a[n]:a[n-1]);
					if(i==n&&j==n-1) {
						for(int k=j-1;k>=1;k--) {
							if(A*2>a[k]&&A+B<a[k]) (ans+=p2[k-1])%=mod;
						}
						// std::cout<<i<<' '<<j<<' '<<ans<<'\n';
						continue;
					}
					if(A*2>C&&A+B<C) {
						(ans+=p2[j-1])%=mod;
					}
					// std::cout<<i<<' '<<j<<' '<<ans<<'\n';
				}
			}
			for(int i=1;i<=n;i++) {
				int A=a[i],C=(i!=n?a[n]:a[n-1]);
				if(A*2>C&&A<C) (ans+=1)%=mod;
			}
			std::cout<<(p2[n]-ans%mod+mod)%mod<<'\n';
		} else if(ccc==18) {
			std::cout<<p2[n]%mod<<'\n';
		}
	}
	return 0;
}

/*

*/
