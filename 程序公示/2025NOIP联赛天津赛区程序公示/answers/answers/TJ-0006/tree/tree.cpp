#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=13+1,Mod=998244353;
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

vector <int> e[N];
bitset <N> bs[N];
int a[N];

int query(int x)
{
	bs[x][a[x]]=1;
	int res=0;
	for(int v:e[x])
	{
		res+=query(v);
		bs[x]|=bs[v]; 
	}
	for(int i=0;i<=n;i++) if(!bs[x][i]) return res+i-1;
	return 0;
}

int res=0;
void dfs(int x)
{
	if(x==0)
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) bs[i][j]=0;
		int w=query(1);
		if(res>=w) return ;
		res=w;
//		printf("res=%d\n",res);
//		for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
		return ;
	}
	
	for(int i=0;i<n;i++)
	{
		a[x]=i;
		dfs(x-1); 
	}
}


void SOLVE()
{
	read(n);read(m);
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=2;i<=n;i++)
	{
		int f;read(f);
		e[f].push_back(i);
	}
	res=0;
	dfs(n);
	printf("%d\n",res);
}
int main()
{
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T=1;
	scanf("%d",&T);
	while(T--) SOLVE();
	return 0;
}
