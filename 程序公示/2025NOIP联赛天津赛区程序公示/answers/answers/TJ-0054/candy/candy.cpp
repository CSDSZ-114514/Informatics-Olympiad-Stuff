#include<cstdio>
#include<cstring>
#include<functional>
#include<algorithm>
template<typename T> bool tense(T &a,const T &b){return b<a?(a=b,true):false;}
template<typename T> bool relax(T &a,const T &b){return b>a?(a=b,true):false;}

int n;
long long m;

namespace Force{
	const int N = 1010,M = 10010;
	int x[N],y[N];
	int v[2*N],w[2*N];
	int f1[M],f2[M];
	
	void solve(){
		for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		for(int i=1;i<=n;i++) v[i] = x[i]+y[i],w[i] = 2,v[i+n] = x[i],w[i+n] = 1;
		for(int i=1;i<=n;i++) for(int j=0;j<=m;j++) if(j>=v[i]) relax(f1[j],f1[j-v[i]]+w[i]);
		for(int i=n+1;i<=2*n;i++) for(int j=m;j>=0;j--) if(j>=v[i]) relax(f2[j],f2[j-v[i]]+w[i]);
		int res = 0;
		for(int m1=0,m2=m;m1<=m;m1++,m2--) relax(res,f1[m1]+f2[m2]);
		printf("%d\n",res);
	}
}
namespace Another{
	const int N = 1e5+10,M = 6e6+10;
	const double eps = 1e-8;
	int x[N],y[N];
	struct Candy{
		long long v,w;
		double x;
		friend bool operator<(const Candy &a,const Candy &b){
			if(std::fabs(a.x-b.x)>eps) return a.x>b.x;
			else if(a.w!=b.w) return a.w>b.w;
			else return a.v<a.v;
		}
	} b[M];
	
	void solve(){
		for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
		int len = 0;
		for(int i=1;i<=n;i++){
			b[++len] = {x[i],1};
			long long k = 1,cnt = m/(x[i]+y[i]);
//			printf("No.%d,cnt = %d\n",i,cnt);
			while(k<=cnt){
				b[++len] = {(x[i]+y[i])*k,2*k};
				k<<=1;
			}
			k>>=1;
			if(cnt-k>0) b[++len] = {(x[i]+y[i])*(cnt-k),2*(cnt-k)};
		}
		for(int i=1;i<=len;i++) b[i].x = 1.0*b[i].w/b[i].v;
//		printf("(v=%d,w=%d)\n",b[i].v,b[i].w);
		std::sort(b+1,b+len+1);
		int res = 0;
		for(int i=1;i<=len;i++) if(m>=b[i].v) m-=b[i].v,res+=b[i].w;
		printf("%d\n",res);
	}
}

int main(){
//	freopen("data1.in","r",stdin);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	if(n<=1000) Force::solve();
	else Another::solve();
	return 0;
}

 
