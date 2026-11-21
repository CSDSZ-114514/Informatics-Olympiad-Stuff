#include<bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
const int N = 5e4;
ull m,ans;
int n,a[N],sum[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		sum[i] = sum[i-1]+a[i];
	}scanf("%ull",&m);
	while(m--){
		int l,r;
		scanf("%d%d",&l,&r);
		for(int i = 1;i <= n;i++){
			int k = -1e9;
			for(int j = l;j <= r;j++){
				for(int o = max(i-j+1,1);o <= min(i+j-1,n);o++){
					k = max(k,sum[o+j-1]-sum[o-1]);
				}
			}//cout << k << endl;
			ans ^= k*i;
		}cout << ans << endl;
		ans = 0;
	}
	
}
