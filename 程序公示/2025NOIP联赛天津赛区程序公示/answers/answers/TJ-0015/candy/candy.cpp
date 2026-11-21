#include <bits/stdc++.h> 
#define int long long
using namespace std;

int n, m, ans, idx;
struct CANDY {
	int x, y;
} c[100010], mc;

bool cmp(CANDY a, CANDY b) {
	return a.x < b.x;
}

signed main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	scanf("%lld%lld", &n, &m), mc.x = mc.y = 2000000000000000000;
	for(int i = 1; i <= n; i++) {
		scanf("%lld%lld", &c[i].x, &c[i].y);
		if(c[i].x+c[i].y <= mc.x+mc.y) mc = c[i];
	}
	sort(c+1, c+n+1, cmp);
	/*for(int i = 1; i <= n; i++) {
		cout << c[i].x << ' ' << c[i].y << ' ';
		if(c[i].x == mc.x && c[i].y == mc.y) cout << "111111111111111111";
		cout << endl;
	}*/
	for(int i = 1; i <= n; i++) {
		if(c[i].x > (mc.x+mc.y)/2 || m < c[i].x) break;
		if(m >= c[i].x) ans++, m -= c[i].x, idx++;
	}
	//cout << ans <<endl;
	//sort(c+1, c+n+1, cmp);
	ans += m/(mc.x+mc.y)*2;
	int sy = m%(mc.x+mc.y);
	//if(sy >= c[1].x) ans++;
	while(idx && sy+c[idx].x >= mc.x+mc.y)
		idx--, sy = sy+c[idx].x-mc.x-mc.y, ans++;
	printf("%lld", ans);
	
	return 0;
}

/*
266

807

9193  -- 34*2 = 68

9044  -- 14 = 82
*/
