#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
template<typename T> bool tense(T &a,const T &b){return b<a?(a=b,true):false;}
template<typename T> bool relax(T &a,const T &b){return b>a?(a=b,true):false;}

int n,q;
const int N = 50010;
long long INF = 0x3f3f3f3f3f3f3f3fll;
int a[N];

namespace Force{
	long long ans[N];
	
	void solve(){
		while(q--){
			int L,R;
			scanf("%d%d",&L,&R);
			for(int i=1;i<=n;i++) ans[i] = -INF;
			for(int len=L;len<=R;len++){
				for(int l=1,r=len;r<=n;l++,r++){
					long long sum = 0;
					for(int i=l;i<=r;i++) sum+=a[i];
					for(int i=l;i<=r;i++) relax(ans[i],sum);
				}
			}
			unsigned long long res = 0;
			for(int i=1;i<=n;i++) res^=(unsigned long long)i*ans[i];
			printf("%llu\n",res);
		}
	}
}
namespace Better{
	const int K = 32;
	long long s[N];
	long long st[K][N];
	int bit[N];
	long long ans[N];
	
	void init(){
		for(int i=1;i<=n+1;i++) st[0][i] = s[i-1];
		for(int k=1;(1<<k)<=n+1;k++){
			for(int i=1;i+(1<<k)-1<=n+1;i++){
				st[k][i] = std::min(st[k-1][i],st[k-1][i+(1<<(k-1))]);
				bit[n+1-i+1] = k;
			}
		}
	}
	long long query(int l,int r){
//		printf("query [%d,%d]\n",l,r);
		l++,r++;
		int k = bit[r-l+1];
		return std::min(st[k][l],st[k][r-(1<<k)+1]);
	}
	void solve(){
		for(int i=1;i<=n;i++) s[i] = s[i-1]+a[i];
		init();
		while(q--){
			int L,R;
			scanf("%d%d",&L,&R);
			for(int i=1;i<=n;i++) ans[i] = -INF;
			for(int i=1;i<=n;i++){
				for(int r=std::max(i,L);r<=n;r++){
					relax(ans[i],s[r]-query(std::max(r-R,0),std::min(r-L,i-1)));
//					for(int l=std::max(r-R,0);l<=(std::min(r-L,i-1));l++) printf("r=%d,valid l:%d\n",r,l),relax(ans[i],s[r]-s[l]);
				}
			}
//			for(int i=1;i<=n;i++) printf("%lld ",ans[i]);puts("");
//			for(int i=1;i<=n;i++) printf("%lld%c\n",ans[i],"  "[i==n]);
			unsigned long long res = 0;
			for(int i=1;i<=n;i++) res^=(unsigned long long)i*ans[i];
			printf("%llu\n",res);
		}
	}
}

int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	scanf("%d",&q);
	if(q<=1) Force::solve();
	else Better::solve();
	return 0;
}

 
