#include<bits/stdc++.h>
using namespace std; 
typedef long long ll; 

struct node{
	int t, w, r; 
} a[5005]; 

int c, t; 
int n, m, cnt, sum; 
int v[100005], dp[5005][5005]; 

bool cmp(node x, node y){
	if(x.r == y.r) return x.t > y.t; 
	return x.r > y.r; 
}

int ck(){
	int ans = 0, p = m; 
	for(int i = 1; i <= n; i++) a[i].r = 2 * a[i].t / a[i].w; 
	sort(a + 1, a + n + 1, cmp); 
	for(int i = 1; i <= n; i++){
		if(p < a[i].w) continue; 
		p -= a[i].w, ans += a[i].t; 
	}
	
	memset(dp, 0, sizeof(dp)); 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			dp[i][j] = dp[i - 1][j]; 
			if(j >= a[i].w) dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - a[i].w] + a[i].t); 
		}
	}
	
	if(ans == dp[n][m]) return 1; 
	return 0; 
}

void dfs(int x){
	if(x > n){
		cnt += ck(); 
		return ; 
	}
	a[x].w = 1, dfs(x + 1); 
	a[x].w = 2, dfs(x + 1); 
}

int main(){
	freopen("sale.in", "r", stdin); 
	freopen("sale.out", "w", stdout); 
	
	scanf("%d%d", &c, &t); 
	while(t--){
		cnt = 0; 
		memset(a, 0, sizeof(a)); 	
		memset(v, 0, sizeof(v)); 
		scanf("%d%d", &n, &m); 
		for(int i = 1; i <= n; i++) scanf("%d", &a[i].t); 
		
		dfs(1); 
		
		printf("%d\n", cnt); 
	}
	return 0; 
} 
