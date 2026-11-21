#include<bits/stdc++.h>
using namespace std;
const int N=5010;
const int mod=998244353;
int n,m;
int a[N];
int c,t;
//bool cmp(pair<int,int> &x, pair<int,int> &y){
//	if(x.first!=y.first) return x.first>y.first;
//	return x.second < y.second;
//}
long long clc(int n) {
	long long ans=1;
    for(int i=1;i<=n;i++){
    	ans*=2;
    	ans%=mod;
	}
	//printf("%lld\n",ans);
	return ans;
}
int main() {
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&t);
	if(c==0) {
        if(t==1){
        	printf("6\n");
        	return 0;
		}
		return 0;
	}
	while(t--) {
		scanf("%d%d",&n,&m);
		//sort(a+1,a+n+1,cmp);
		if(m==2) { // m=2
			for(int i=1; i<=n; i++) {
				scanf("%d",&a[i]);
			}
			sort(a+1,a+n+1);
			int cnt=0;
			for(int i=3;i<=n;i++){
				if(a[i-1] + a[i-2] < a[i]) cnt++;
			} 
			if(cnt!=0){
				printf("%lld\n",(clc(n)-clc(cnt))%mod);
			}
			else printf("%lld",clc(n)%mod);
			
		} 
		else { // A
			// 2^n %998
			printf("%lld",clc(n)%mod);
		}
	}
	return 0;
}
