#include <bits/stdc++.h>

using namespace std;

int n, a[100001], b[100001], where;
long long m, c[100001], d[100001], sum;

int main (){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	scanf ("%d%lld", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf ("%d%d", &a[i], &b[i]);
		c[i] = 1LL * (a[i] + b[i]);
	}
	sort(a + 1, a + n + 1);
	long long cma = 1 << 30;
	for (int i = 1; i <= n; i++)
		cma = min (cma, c[i]);
	long long ans = 0;
	long long aall = 0;
	long long p = 0;
	for (int i = 1; i <= n; i++){
		aall += a[i] * 1LL;
	}
	if (m > aall){
		ans += ((m - aall) / cma) * 2;
		p = aall + (m - aall) % cma;
	}
	else{
		p = m;
	}
	for (int i = 1; i <= n; i++){
		d[i] = a[i] + d[i - 1] + 0LL;
		if (d[i] <= p)
			where = i;
	}
	for (int i = 0; i <= where; i++){
		sum = max(sum, i + ((p - d[i]) / cma) * 2);
	}
	ans += (sum * 1LL);
	printf ("%lld\n", ans);
	return 0;
} 
