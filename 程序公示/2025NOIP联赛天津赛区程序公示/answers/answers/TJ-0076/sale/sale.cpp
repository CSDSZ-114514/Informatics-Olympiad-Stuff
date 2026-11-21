#include<bits/stdc++.h>
using namespace std;
int op[100005],dp[100005];
int n,m,maxn,ans;
struct node{
	int a;
	int b;
	int c;
	int d;
}a[5005];
bool cmp(node a,node b){
	if(a.c!=b.c)return a.c>b.c;
	else if(a.a!=b.a)return a.a>b.a;
	else return a.d<b.d;
}
void dfs(int t){
	if(t==n+1){
		sort(a+1,a+1+n,cmp);
		int sum=0;
		int p=1;
		for(int i=1;i<=n;i++){
			if(m>=a[i].b){
				m-=a[i].b;
				sum+=a[i].a;
			}
			
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=n;j>=a[i].b;j--){
				dp[j]=max(dp[j],dp[j-a[i].b]+a[i].a);
			}
		}
		if(sum==dp[m])ans++;
		return;
	}
	for(int i=1;i<=2;i++){
		a[t].b=i;
		int u=a[t].a;
		u*=2;
		a[t].c=u/i;
		dfs(t+1);
	}
}
int main(){
	int c,T;
	scanf("%d%d",&c,&T);
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	while(T--){
		maxn=-1;
		memset(op,0x3f,sizeof(op));
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i].a);
			a[i].d=i;
		}
		dfs(1); 
		printf("%d\n",ans);
	}
} 
//0 1 3 2 1 3 5
