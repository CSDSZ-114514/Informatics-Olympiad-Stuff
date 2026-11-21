#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 50004 // 2e6
const int inf=1e18+7;
int T,n,q,a[M],s[M],ans[M];
int f[34][34][M],up;
int sx[3005][3005];
unsigned long long opt;
int val[M],qe[M],ql,qr;
void Calc1(int x) {
	for(int i=1;i<=n-x+1;i++) val[i]=s[i+x-1]-s[i-1];
	for(int i=n-x+2;i<=n;i++) val[i]=-inf;
	ql=1,qr=0;
	for(int i=1;i<=n;i++) {
		while(qr>=ql&&val[qe[qr]]<=val[i]) qr--;
		qe[++qr]=i;
		while(qr>=ql&&qe[ql]<i-x+1) ql++;
		ans[i]=val[qe[ql]];
	}
}
signed main() {
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n;
	for(int i=1;i<=n;i++) std::cin>>a[i],s[i]=s[i-1]+a[i];
	if(n<=3000) {
		for(int i=1;i<=n;i++) {
			sx[i][i]=s[i];
			for(int j=i+1;j<=n;j++)
				sx[i][j]=std::max(s[j],sx[i][j-1]);
		}
		std::cin>>q;
		for(int _q=1,lo,ro;_q<=q;_q++) {
			std::cin>>lo>>ro;
			opt=0;
			for(int i=1;i<=n;i++) {
				int ax=-inf;
				for(int l=1;l<=i;l++) {
					int kl=l+lo-1,kr=l+ro-1;
					if(kr>n) kr=n; if(kl<i) kl=i;
					if(kl>kr) continue;
					ax=std::max(ax,sx[kl][kr]-s[l-1]);
				}
				// std::cout<<i<<' '<<lo<<' '<<ro<<' '<<ax<<'\n';
				opt^=(unsigned long long)i*(unsigned long long)ax;
			}
			std::cout<<opt<<'\n';
		}
		return 0;
	}
	std::cin>>q,up=(n<=32?n:32);
	for(int i=1;i<=up;i++) Calc1(i),memcpy(f[i][i],ans,sizeof ans); 
	for(int i=1;i<=n;i++)
		for(int l=1;l<=up;l++)
			for(int r=l+1;r<=up;r++)
				f[l][r][i]=std::max(f[r][r][i],f[l][r-1][i]);
	for(int _q=1,lo,ro;_q<=q;_q++) {
		std::cin>>lo>>ro;
		if(ro<=up) {
			opt=0;
			for(int i=1;i<=n;i++) opt^=(unsigned long long)i*(unsigned long long)f[lo][ro][i];
			std::cout<<opt<<'\n';
		} else {
			Calc1(lo);
			opt=0;
			for(int i=1;i<=n;i++) opt^=(unsigned long long)i*(unsigned long long)ans[i];
			std::cout<<opt<<'\n';
		}
	}
	return 0;
}

/*

*/