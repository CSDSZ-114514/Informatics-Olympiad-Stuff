#include <bits/stdc++.h>

using namespace std;

int c, t, n, m, a[5100], w[5100], sum, a1[5100], jishu;

bool cmp(int x, int y){
	if (x > y){
		swap(w[x], w[y]);
		return y;
	}
	else
		return x;
}

inline void dfs(int p){
	if (p == n + 1){
		jishu++;
		if (jishu == 4){
			for (int i = 1; i <= n; i++)
				printf ("%d ", w[i]);
			printf ("\n");
		}
		for (int i = 1; i <= n; i++){
			if (w[i] == 2)
				a1[i] = a[i] * 2;
			else
				a1[i] = a[i];
		}
		sort(a1 + 1, a1 + n + 1, cmp);
		int where = 0;
		int t = m;
		for (int i = 1; 1 == 1; i++){
			if (t >= w[i]){
				where = i;
				t -= w[i];
			}
			else
				break;
		}
		int x = 0, y = 0;
		for (int i = where; i >= 1; i--){
			if (w[i] == 1){
				x = i;
				break;
			}
		}
		for (int i = where; i <= n; i++){
			if (w[i] == 2){
				y = i;
				break;
			}
		}
		if (y && x && (!m) && a[x] < a[y]){
			sum++;
			if (sum >= 998244353)
				sum -= 998244353;
		}
		where = 0;
		return;
	}
	w[p] = 1;
	dfs(p + 1);
	w[p] = 2;
	dfs(p + 1);
	return;
}

int main (){
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w", stdout);
	scanf ("%d%d", &c, &t);
	for (int i = 1; i <= t; i++){
		scanf ("%d%d", &n, &m);
		for (int j = 1; j <= n; j++)
			scanf ("%d", &a[j]);
		int t = 1; 
		for (int j = 1; j <= n; j++){
			t *= 2;
			if (t >= 998244353)
				t -= 998244353;
		}
		bool flag = true;
		for (int i = 1; i <= n; i++){
			if (a[1] != a[i])
				flag = false; 
		}
		if (flag){
			printf ("%d\n", t);
			continue;
		}
		//dfs(1);
	//	if (sum > t)
		//	t += 998244353;
	//	printf ("%d\n", t - sum);
	}
	return 0;
} 
