#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const N=5010;
ll const P=998244353;
ll a[N];
int c,t;
int n,m,w1[N],w2[N];
ll f[N][N<<1];
bool g[N];
ll res;

struct node{
	int x,s;
} w[N];

ll Pow(ll x,int a){
	if (a==0) return 1;
	if (a==1) return x;
	ll pw=Pow(x,a>>1);
	if (a%2) return (pw*pw*x)%P;
	return (pw*pw)%P;
}

bool cmp(node x,node y){
	if (x.s==y.s) return a[x.x]>a[y.x];
	return x.s>y.s;
}

bool judge(){
	for (int i=1;i<=n;i++) for (int j=1;j<=m;j++) f[i][j]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1]);
			if (j>=1+g[i]) f[i][j]=max(f[i][j],f[i-1][j-1-g[i]]+a[i]);
		}
	}
	for (int i=1;i<=n;i++) w[i].x=i,w[i].s=a[i]*(g[i]?1:2);
	sort(w+1,w+n+1,cmp);
	ll tmp=0,v=m;
	for (int i=1;i<=n;i++){
		if (v>=g[w[i].x]+1){
			v-=g[w[i].x]+1;
			tmp+=a[w[i].x];
		}
	}
	//printf("%lld %lld\n",f[n][m],tmp);
	return tmp==f[n][m];
}

void solve1(int x){
	if (x>n){
		if (judge()){
			res++,res%=P;
			//for (int i=1;i<=n;i++) printf("%d ",g[i]+1);
			//printf("\n");
		}
		return;
	}
	solve1(x+1);
	g[x]=1;
	solve1(x+1);
	g[x]=0;
	return;
}

void solve2(){
	sort(a+1,a+n+1);reverse(a+1,a+n+1);
	int k,p;
	for (k=1;k<=n;k++){
		if (a[k]*2<a[1]){
			k--;break;
		}
	} 
	res=Pow(2,n-1)+Pow(2,n-k);
	for (k=1;k<=n;k++){ //find 1st
		if (a[1]!=a[k]){
			break;
		}
	}
	p=k;
	for (;p<=n;p++){ //find 2nd
		if (a[p]!=a[k]){
			p--;break;
		}
	}
	k--;
	
}

int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	scanf("%d %d",&c,&t);
	for (int i=1;i<=t;i++){
		res=0,
		scanf("%d %d",&n,&m);
		for (int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if (c<=5){
			solve1(1);
			//printf("%d\n",res);
		}
		if (7<=c && c<=9){
			solve2();
		}
		printf("%d\n",res);
	}
	
	return 0;
} 
