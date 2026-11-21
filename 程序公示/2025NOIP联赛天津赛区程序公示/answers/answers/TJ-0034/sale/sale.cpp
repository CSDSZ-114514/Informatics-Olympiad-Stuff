#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5010,mod=998244353;
int C,T;
int n,m,a[N];
int f[N];
struct Candy{
	int a,w,idx;
}data[N];

bool cmp(Candy p,Candy q){
	if(p.a*q.w!=q.a*p.w)return p.a*q.w>q.a*p.w;
	else if(p.a!=q.a)return p.a>q.a;
	else return p.idx<q.idx;
}

signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
		
		int ans=0;
		for(int i=0;i<(1<<n);++i){
			for(int j=1;j<=n;++j){
				data[j].idx=j;
				data[j].a=a[j];
				if((i>>(j-1)&1)==0)data[j].w=1;
				else data[j].w=2;
			}
			sort(data+1,data+1+n,cmp);
			
			int test_m=m,sum=0;
			for(int j=1;j<=n;++j){
				if(test_m>=data[j].w){
					test_m-=data[j].w;
					sum+=data[j].a;
				}
			}
			
			memset(f,0,sizeof(f));
			for(int j=1;j<=n;++j)
				for(int k=m;k>=data[j].w;--k)
					f[k]=max(f[k],f[k-data[j].w]+data[j].a);
			
			if(sum==f[m])ans=(ans+1)%mod;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
