#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;

const int MAXN = 1e7+5;
int n,m,dp[MAXN];
int cost[MAXN*2],type[MAXN*2];
int min1=1e18,min2=1e18;
bool flag1,flag2;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);

	cin >> n >> m;
	int pos = 0,x,y;
	for(int i=1;i<=n;i++){
		cin >> x >> y;
		if(x!=y) flag1 = false;
		if(x<y) flag2 = false;
		min1 = min(min1,x);
		min2 = min(min2,x+y); 
		cost[++pos] = x, type[pos] = 1;
		cost[++pos] = x+y, type[pos] = 2;
	}
	
	if(flag1&&(n>1000||m>10000)){
		int ans = m/min1;
		cout << ans;
		return 0;
	}
	
	if(flag2&&(n>1000||m>10000)){
		int cnt = m/min2, ans = 0;
		ans += 2*cnt;
		m -= cnt*min2;
		if(m>=min1) ans++;
		cout << ans;
		return 0;
	} 
	
	for(int i=1;i<=2*n;i++){
		if(type[i]==1){
			for(int j=m;j>=1;j--){
				if(j>=cost[i]) dp[j] = max(dp[j],dp[j-cost[i]]+1);
			}
		}else{
			for(int j=1;j<=m;j++){
				if(j>=cost[i]) dp[j] = max(dp[j],dp[j-cost[i]]+2);
			}	
		}
	}
	
	cout << dp[m];

	return 0;
}
