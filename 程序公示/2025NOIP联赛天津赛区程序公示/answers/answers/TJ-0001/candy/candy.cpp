#include <bits/stdc++.h>
using namespace std;
#define int long long
#define M 200005 // 2e5
const int inf=1e18+7;
int T,n,m,a[M],b[M],in=inf,ans;
signed main() {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n>>m;
	for(int i=1;i<=n;i++) std::cin>>a[i]>>b[i],in=std::min(in,a[i]+b[i]);
	std::sort(a+1,a+n+1);
	for(int i=0;i<=n;i++) {
		m-=a[i];
		if(m<0) break;
		ans=std::max(ans,i+m/in+m/in);
	}
	std::cout<<ans;
	return 0;
}

/*

*/