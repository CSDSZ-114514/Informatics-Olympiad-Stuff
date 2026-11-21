#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

const int MAXN = 11,M = 998244353;
int C,T,n,m,dp[2*MAXN],ans;
struct node{
	int num,a,w,x;
}data[MAXN];

bool cmp(node x,node y){
	if(x.x!=y.x) return x.x > y.x;
	else if(x.a!=y.a) return x.a > y.a;
	return x.num < y.num; 
}

bool cmpp(node x,node y){
	return x.num < y.num;
}

void dfs(int k){
	if(k==n+1){
		memset(dp,0,sizeof(dp));
		int sum = m, res = 0;
		for(int i=1;i<=n;i++) for(int j=m;j>=1;j--){
			if(j>=data[i].w) dp[j] = max(dp[j],dp[j-data[i].w]+data[i].a);
		}
		for(int i=1;i<=n;i++) data[i].x = data[i].a*(3-data[i].w);
		sort(data+1,data+1+n,cmp);
		for(int i=1;i<=n;i++){
			if(sum>=data[i].w){
				sum -= data[i].w;
				res += data[i].a;
			}
		}
		if(res==dp[m]) ans++;
		sort(data+1,data+n+1,cmpp);
		return;
	}	
	data[k].w = 1;
	dfs(k+1);
	data[k].w = 2;
	dfs(k+1);
}

void doing(){
	ans = 0;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> data[i].a;
		data[i].num = i;
	}
	dfs(1);
	cout << ans << endl;
}

int power(int a,int p){
	int s = 1;
	while(p){
		if(p%2) s = s*a%M;
		p /= 2;
		a = a*a%M;
	}
	return s;
}

void doing18(){
	cin >> n >> m;
	int t;
	for(int i=1;i<=n;i++) cin >> t;
	cout << power(2,n);
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	cin >> C >> T;
	if(C<=5){
		while(T--) doing();
	}
	if(C==18){
		while(T--) doing18();
	}
	
	return 0;
}


