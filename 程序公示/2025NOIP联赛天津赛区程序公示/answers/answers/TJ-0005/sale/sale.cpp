#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define mid ((l+r)>>1)
using namespace std;
const int N=5050+5,mod=998244353;
int n,m,a[N],f[N];
struct node{
	int a,x;
}b[N];
int inv[N],fac[N];
inline int read(){int x(0),f(1);char ch=getchar();for(;!isdigit(ch);ch=getchar())if(ch=='-')f=-1;for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);return x*f;}
void init(int n){
	inv[0]=inv[1]=fac[0]=fac[1]=1;
	for(int i=2;i<=n;i++) fac[i]=fac[i-1]*i%mod,inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++) inv[i]=inv[i]*inv[i-1]%mod;
}
int C(int n,int m){
	if(n<m) return 0;
	if(!n) return 1;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int ksm(int a,int b){
	if(b<0) return 1;
	int res=1;
	for(;b;b>>=1,a=a*a%mod) if(b&1) res=res*a%mod;
	return res;
}
signed main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
//	int cc=clock();
	int c=read(),T=read();
	init(N-5);
	while(T--){
		n=read(),m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		sort(a+1,a+n+1);
		int ans=ksm(2,n);
		if(a[1]==a[n]||m==2*n-1||m==1){
			printf("%lld\n",ans);
			continue;
		}
		if(n<=20){
			ans=0;
			for(int i=0;i<(1<<n);i++){
				for(int j=1;j<=n;j++) b[j]={a[j],((i>>(j-1))&1)+1};
				sort(b+1,b+n+1,[](node a,node b){return a.a*b.x==b.a*a.x?a.a>b.a:a.a*b.x>b.a*a.x;});
				int w=m,res=0,ss=0;bool flag=0;
				for(int j=1;j<=n;j++){
					if(w>=b[j].x){
						w-=b[j].x,res+=b[j].a;
					}
				}
				memset(f,0,sizeof(f));
				for(int j=1;j<=n;j++){
					for(int k=m;k>=b[j].x;k--){
						f[k]=max(f[k],f[k-b[j].x]+b[j].a);
					}
				}
				if(f[m]!=res){
	//				for(int j=1;j<=n;j++) printf("%d %d\n",b[j].x,b[j].a);
	//				printf("  %d %d\n",f[m],res);
				}
				else ans++;
			}
			printf("%lld\n",ans);
		}
		else{
			ans=ksm(2,n);
			for(int y=1;y<=n;y++){
				for(int x=1;x<y;x++){
					for(int z=y+1;z<=n;z++) if(a[x]+a[y]<a[z]&&a[y]*2>a[z]){
						int a1=z-y-1,a2=n-z;
						int mm=m-2-a2,tt=a1+a2;
						if(mm<0||mm<tt) continue;
						ans-=ksm(2,x-1)*C(mm,tt);
					}
				}
			}
			for(int x=1;x<=n;x++){
				for(int z=x+1;z<=n;z++) if(a[x]*2>a[z]){
					int a1=z-x-1,a2=n-z;
					int mm=m-1-a2,tt=a1+a2;
					if(mm<0||mm<tt) continue;
					ans-=ksm(2,x-1)*C(mm,tt)/2;
				}
			}
			printf("%lld\n",ans);
		}
	}
//	printf("\n%lld",clock()-cc);
	return 0;
}
/*
0 1
5 5
483903342 335678433 241951671 241951671 251607302

*/
