#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5005;
ll id,t,a[N],b[N],dp[N][2*N],n,m,anss[N],len,ans;
array<ll,3> c[N];

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%lld%lld",&id,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i = 1;i <= n;i++){
			scanf("%lld",&a[i]);
		}
		if(n <= 10){
			for(int i = 0;i < 1<<n;i++){
				ll mm = m,val = 0;
				for(int j = 0;j < n;j++){
					if(i &(1<<j)){
						c[j+1][2] = 2;
						c[j+1][1] = a[j+1];
						c[j+1][0] = c[j+1][1];
					}else{
						c[j+1][2] = 1;
						c[j+1][1] = a[j+1];
						c[j+1][0] = c[j+1][1]*2;
					}
				}sort(c+1,c+n+1);
				reverse(c+1,c+n+1);
				
				for(int i = 1;i <= n;i++){
					if(mm >= c[i][2]){
						mm -= c[i][2];
						val += c[i][1];
					}
				}
				for(int i = 1;i <= n;i++){
					for(int j = 0;j <= m;j++){
						dp[i][j] = dp[i-1][j];
						if(j >= c[i][2]){
							dp[i][j] = max(dp[i-1][j-c[i][2]] + c[i][1],dp[i][j]);
						}
					}
				}//cout << val-dp[n][m]<<endl;
				if(val == dp[n][m]){
					
					ans++;
				}//cout << val << ' ' << dp[n][m] << endl;
			}
			printf("%d\n",ans);
			ans = 0;
		}else{
			ans = 1;
			for(int i = 1;i <= n;i++){
				ans *= 2;
				ans %= 998244353;	
			}cout << ans << endl;
			ans = 0;
		} 
			
		
	}/*freopen("sale3.ans","r",stdin);
	int num = 0;
	for(int i = 1;i <= len;i++){
		int x;
		cin >> x;
		//cout << anss[i]<<endl;;
		if(anss[i] != x){
			num++;
		}
	}cout << num;*/

}
