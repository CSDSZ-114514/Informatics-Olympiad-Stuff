#include<bits/stdc++.h>
using namespace std; 
typedef long long ll; 

struct node{
	int index; 
	ll v[2]; 
} a[100005]; 

ll n, m, ans, sum; 
bool vis[100005]; 

bool cmp1(node p, node q){
	return p.v[0] < q.v[0]; 
}
bool cmp2(node p, node q){
	return p.v[0] + p.v[1] < q.v[0] + q.v[1];  
}

int main(){
	freopen("query.in", "r", stdin); 
	freopen("query.out", "w", stdout); 
	
	scanf("%lld%lld", &n, &m); 
	for(int i = 1; i <= n; i++) scanf("%lld%lld", &a[i].v[0], &a[i].v[1]), a[i].index = i; 
	sort(a + 1, a + n + 1, cmp2); 
	
	node t = a[1]; 
	ans = m / (t.v[0] + t.v[1]) * 2; 
	sum = m % (t.v[0] + t.v[1]); 
	if(m % (t.v[0] + t.v[1]) >= t.v[0]) ans++, sum -= t.v[0]; 
	
	int cnt = 0; 
	sort(a + 1, a + n + 1, cmp1); 
	for(int i = 1; i <= n; i++){
		if(t.index == a[i].index or vis[i] == 1) continue; 
		
		ll sub = t.v[(ans + 1) % 2] - a[i].v[0]; 
		if(sub > 0) ans--, cnt++, sum += sub, vis[i] = 1, i = 0; 
	}
	ans += (sum / (t.v[0] + t.v[1]) * 2); 
	sum = sum % (t.v[0] + t.v[1]); 
	
	bool flg = 0; 
	for(int i = 1; i <= n; i++){
		if(sum < a[i].v[0]) break; 
		if(sum >= t.v[ans % 2] and t.v[ans % 2] <= a[i].v[0] and flg == 0){
			flg = 1, cnt++; 
			sum -= t.v[ans % 2]; 
			continue; 
		} 
		
		if(t.index == a[i].index or vis[i] == 1) continue; 
		sum -= a[i].v[0]; 
		cnt++; 
	}
	
	printf("%lld", ans + cnt); 
	return 0; 
} 
