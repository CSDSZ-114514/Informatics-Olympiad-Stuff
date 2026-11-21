#include <bits/stdc++.h>
#define int long long 
using namespace std;
struct node{
	int x,y,id;
}aa[100001];
int n,m,minn = 1e12,cnt,xx,idd,tot,ans;
bool cmp(node a,node b){
	return a.x < b.x;
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1;i <= n;i++){
		scanf("%lld%lld",&aa[i].x,&aa[i].y);
		aa[i].id = i;
		if (aa[i].x + aa[i].y < minn){
			minn = aa[i].x + aa[i].y;
			idd = i;
			xx = aa[i].x;
		}
	}
	sort(aa + 1,aa + n + 1,cmp);
	int tot2 = m % minn;
	if (tot2 >= xx){
		ans = max(ans,(m / minn) * 2 + 1);
	}else{
		ans = max(ans,(m / minn) * 2);
	}
	for (int i = 1;i <= n;i++){
		if (aa[i].id == idd){
			continue;
		}
		cnt++;
		tot += aa[i].x;
		if (tot > m){
			continue;
		}
		int x1 = m - tot;
		int cnt1 = cnt,tot1 = x1 % minn;
		cnt1 += (x1 / minn) * 2;
		if (tot1 >= xx){
			cnt1++;
		}
		ans = max(ans,cnt1);
	}
	printf("%lld",ans);
	return 0;
}
