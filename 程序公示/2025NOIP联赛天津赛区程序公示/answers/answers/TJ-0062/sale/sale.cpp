#include<bits/stdc++.h>
using namespace std;

typedef int INT;
#define int long long

const int MOD = 998244353;
const int N = 5010;
const int M = N*2;

int taskidx;
int n, money;
int ans;
int a[N];	//全都乘了2，便于除2 
int w[N];
int idx[N];
int dp[N];

int read(){
	int num = 0;
	char c = getchar();
	while(!isdigit(c)){
		c = getchar();
	}
	while(isdigit(c)){
		num = (num << 1) + (num << 3) + c - '0';
		c = getchar();
	}
	return num;
}

bool cmp(int i1, int i2){
	if(a[i1]/w[i1] != a[i2]/w[i2]){
		return a[i1]/w[i1] > a[i2]/w[i2];
	}else{
		return a[i1] > a[i2];
	}
}

bool Solve(){
	for(int i = 1; i <= n; i ++){
		idx[i] = i;
	}
	sort(idx+1, idx+1+n, cmp);
	int m = money;
	int p = 1;
	int r_sum = 0;
	while(m > 0 && p <= n){
		if(m >= w[idx[p]]){
			r_sum += a[idx[p]];
			m -= w[idx[p]];
		}
		p ++;
	}
	for(int i = 0; i <= money; i ++){
		dp[i] = 0;
	}
	for(int i = 1; i <= n; i ++){
		for(int j = money; j >= 1; j --){
			if(j >= w[i]) dp[j] = max(dp[j], dp[j-w[i]] + a[i]);
		}
	}
	//printf("%lld, %lld\n", r_sum, dp[money]);
	return dp[money] == r_sum;
}

void Try(int i){
	if(i == n+1){
		if(Solve()){
			ans = (ans + 1) % MOD;
		}
	}else{
		w[i] = 1;
		Try(i+1);
		w[i] = 2;
		Try(i+1);
		w[i] = 1;
	}
}

void InitIO(){
	ans = 0;
	n = read();
	money = read();
	for(int i = 1; i <= n; i ++){
		a[i] = read()*2;
	}
	Try(1);
	printf("%lld\n", ans);
}

INT main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	int T;
	taskidx = read();
	T = read();
	while(T --){
		InitIO();
	}
	return 0;
}
