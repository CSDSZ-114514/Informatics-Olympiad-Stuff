#include<bits/stdc++.h>

using namespace std;

struct g{
	long long a,b,c;
};

long long c,t,n,m,a[5005],ans,b[5005],ans2;

g z[5005];
int cmp(g x,g y){
	return double(x.a / x.b) > double(y.a / y.b) or double(x.a / x.b) == double(y.a / y.b) and x.a > y.a;
}

void solve2(int p,long long cnt,long long h){
	if (p == n+1){
		if (h >= 0){
			ans = max(ans,cnt);
		}
		return;
	}
	solve2(p+1,cnt,h);
	solve2(p+1,cnt+a[p],h - b[p]);
}

void solve(int p){
	if (p == n+1){
		
		ans = 0;
		solve2(1,0,m);
		for (int i = 1;i <= n;i++){
			//if (t == 995) cout << b[i]<<' ';
			z[i].a = a[i];
			z[i].b = b[i];
			z[i].c = i;
		}
		//if (t == 995) cout << endl;
		sort(z+1,z+1+n,cmp);
		long long mo = m,maxx=0;
		for (int i = 1;i <= n;i++){
			if (mo >= z[i].b){
				mo -= z[i].b;
				maxx += z[i].a;
			}
		}
		
		//if (t == 995) cout << maxx << ' ' << ans << endl;
		if (maxx == ans) ans2++;
		return;
	}
	b[p] = 1;
	solve(p+1);
	b[p] = 2;
	solve(p+1);
	b[p] = 1;
	
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin >> c >> t;
	while (t--){
		//t--;
		cin >>n >> m;
		for (int i = 1;i <= n;i++) cin >> a[i];
		ans2 = 0;
		solve(1);
		cout << ans2 << endl;
	}
	return 0;
}
