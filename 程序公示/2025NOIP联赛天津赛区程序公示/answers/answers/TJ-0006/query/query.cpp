#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e5+10,Mod=998244353;
int n,m,k;

template <typename T> void tomax(T &a,const T &b){if(a<b) a=b;}
template <typename T> void tomin(T &a,const T &b){if(a>b) a=b;}
void modadd(int &a,const int &b){a+=b;if(a<0) a+=Mod;if(a>=Mod) a-=Mod;}
void modsub(int &a,const int &b){a-=b;if(a<0) a+=Mod;if(a>=Mod) a-=Mod;}
void modmul(int &a,const int &b){a=1ll*a*b%Mod;}
int ksm(int a,int b){int res=1;while(b){if(b&1) modmul(res,a);modmul(a,a);b>>=1;}return res;}
int inv(int x){return ksm(x,Mod-2);}
void read(int &x){scanf("%d",&x);}
void read(LL &x){scanf("%lld",&x);}

LL ans[N];
LL a[N];

void SOLVE()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]),a[i]+=a[i-1],ans[i]=0;
	read(m);
	while(m--)
	{
		int l,r;
		for(int i=1;i<=n;i++) ans[i]=-1e18;
		read(l),read(r); 
		for(int len=l;len<=r;len++)
		{
			for(int i=1;i<=n;i++)
			{
				int j=i+len-1;
				if(j>n) break;
				LL sum=a[j]-a[i-1];
				for(int k=i;k<=j;k++)
				{
					tomax(ans[k],sum);
				}
			}
		}
//		for(int i=1;i<=n;i++) printf("%lld ",ans[i]);puts("");
		unsigned LL res=0;
		for(int i=1;i<=n;i++)
		{
			unsigned LL w=ans[i];
//			printf("w=%llu\n",w);
			res^=w*i;
		}
		printf("%llu\n",res);
	 } 
	
}
int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) SOLVE();
	return 0;
}
