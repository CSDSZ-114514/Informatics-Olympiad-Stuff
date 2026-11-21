#include <bits/stdc++.h>
using namespace std;
const long long M=998244353;
struct node{
	long long a,id,b;
	double d;
};
node c[110000];
long long bits[1100];
long long dp[1100][1100];
bool cmp(node a,node b){
	if(a.d!=b.d)return a.d>b.d;
	else if(a.a!=b.a)return a.a>b.a;
	else return a.id<b.id;
}
bool cmp2(node a,node b){
	return a.id<b.id;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	long long r,t;
	scanf("%lld%lld",&r,&t);
	while(t--){
		for(long long i=0;i<=100000;++i){
			c[i].a=0;
			c[i].id=0;
			c[i].d=0.0;
		}
		long long ans=0;
		long long n,m;
		scanf("%lld%lld",&n,&m);
		int flag=1;
		long long sum2=0;
		long long min1=1e18;
		for(int i=1;i<=n;++i){
			scanf("%lld",&c[i].a);
			sum2+=c[i].a;
			min1=min(min1,c[i].a);
			c[i].id=i;
			if(c[i].a!=c[max(i-1,1)].a)flag=0;
		}
		if(flag==1 or m==2*n-1){
			long long res=2;
			for(long long i=2;i<=n;++i){
				res*=2;
				res%=M;
			}
			printf("%lld\n",res);
			continue;
		}
		
		
		if(m==2*n-2){
			long long res=2;
			for(long long i=2;i<=n;++i){
				res*=2;
				res%=M;
			}
			for(long long i=1;i<=n;++i)bits[i]=2;
			for(long long i=1;i<=n;++i){
				bits[i-1]=2;
				bits[i]=1;
				for(long long i=1;i<=n;++i){
					c[i].d=1.0*c[i].a/bits[i];
					c[i].b=bits[i];
				}
				sort(c+1,c+n+1,cmp);
				if(min1!=c[n].a)res--;
			}
			printf("%lld\n",res);
			continue;	
		}
		
		memset(bits,0,sizeof bits);
		for(long long b=0;b<pow(2,n);++b){
			sort(c+1,c+n+1,cmp2);
			memset(dp,0,sizeof dp);
			long long bb=b;
			for(long long i=1;i<=n;++i){
				bits[n+1-i]=(bb&1)+1;
				bb>>=1;
			}
			for(long long i=1;i<=n;++i){
				for(long long j=m;j>0;--j){
					dp[i][j]=dp[i-1][j];
					if(j>=bits[i])dp[i][j]=max(dp[i][j],dp[i-1][j-bits[i]]+c[i].a);
				}
			}
			long long best=dp[n][m];
			for(long long i=1;i<=n;++i){
				c[i].d=1.0*c[i].a/bits[i];
				c[i].b=bits[i];
			}
			sort(c+1,c+n+1,cmp);
			long long mm=m;
			long long sum=0;
			for(long long i=1;i<=n;++i){
				if(mm<c[i].b)continue;
				mm-=c[i].b;
				sum+=c[i].a;
			}
			if(sum==best)ans++;
			ans%=M;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

