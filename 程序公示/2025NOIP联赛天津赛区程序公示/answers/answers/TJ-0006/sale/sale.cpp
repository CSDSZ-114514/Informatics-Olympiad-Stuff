#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define pii pair<int,int>
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

int fac[N],invfac[N];
void init()
{
	fac[0]=invfac[0]=1;
	for(int i=1;i<N;i++) fac[i]=1ll*fac[i-1]*i%Mod;
	invfac[N-1]=inv(fac[N-1]);
	for(int i=N-2;i;i--) invfac[i]=1ll*invfac[i+1]*(i+1)%Mod;
}
int C(int x,int y){if(x<y) return 0;else return 1ll*fac[x]*invfac[x-y]%Mod*invfac[y]%Mod;}

int a[N];
vector <pii> t;

namespace q1{
	void SOLVE()
	{
		read(n),read(m);
//		puts("QAQ");
		for(int i=1;i<=n;i++) read(a[i]);
		sort(a+1,a+1+n);
		reverse(a+1,a+1+n);
//		int w=-1;
		int res=ksm(2,n);
		for(int i=2;i<=n;i++)
		{
			if(a[1]>=a[i]*2) continue;
			for(int j=i+1;j<=n;j++)
			{
//				printf("(%d,%d)\n",i,j);
				if(a[i]+a[j]<a[1])
				{
//					printf("(%d,%d)\n",i,j);
					modsub(res,ksm(2,n-j));
				}
			}
		}
		printf("%d\n",res);
	}
}

int num;
void dfs(int id)
{
	if(id>n)
	{
		vector <pii> w=t;
		sort(w.begin(),w.end());
		reverse(w.begin(),w.end()); 
		int mm=m,a1=0,a2=0,a3=0,sz=0;
		for(int i=0;i<n;i++)
		{
			if(mm<=0) break;
			if(mm<=1&&w[i].second==2)
			{
				tomax(a1,w[i].first);
				continue;
			}
			if(w[i].second==1) a3=a2,a2=w[i].first/2,sz++;
			mm-=w[i].second;
		}
		if(a1==0||a2==0||(sz==1&&mm==0))
		{
			num++;
			return ;
		}
		if(mm>=1) a3=0;
		if(a2+a3>=a1) num++;
		else
		{
//			printf("if:");
//			for(int i=0;i<n;i++) printf("(%d,%d) ",w[i].first/(2/w[i].second),w[i].second);puts("");
//			printf("a1=%d,a2=%d,a3=%d(%d)\n",a1,a2,a3,a2+a3);
		}
		
		return ;
	}
	t[id-1]={a[id]*2,1};
	dfs(id+1);
	t[id-1]={a[id],2};
	dfs(id+1); 
}


void SOLVE()
{
	read(n),read(m);
	for(int i=1;i<=n;i++) read(a[i]);
	if(m==1) return printf("%d\n",ksm(2,n)),void();
	num=0;t.resize(n);
	dfs(1);
	printf("%d\n",num);
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	int C=0,T=1;
	scanf("%d %d",&C,&T);
	init();
	if(C==7||C==8||C==9||C==14||C==15)
	{
		while(T--) q1::SOLVE();
		return 0;
	}
	while(T--) SOLVE();
	return 0;
}
