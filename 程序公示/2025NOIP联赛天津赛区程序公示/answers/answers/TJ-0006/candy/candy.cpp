#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1e6+10,Mod=998244353;
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

int a[N],b[N],mn=2e9;
void SOLVE()
{
	LL m;
	read(n);read(m);
	for(int i=1;i<=n;i++) read(a[i]),read(b[i]),tomin(mn,a[i]+b[i]);
	sort(a+1,a+1+n);
	LL res=0;
	for(int i=0;i<=n;i++)
	{
		m-=a[i];
		tomax(res,i+(m/mn)*2);
	}
	cout<<res;
}
int main()
{
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int T=1;
//	scanf("%d",&T);
	while(T--) SOLVE();
	return 0;
}
