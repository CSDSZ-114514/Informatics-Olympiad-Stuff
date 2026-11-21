#include<bits/stdc++.h>
using namespace std;
int cc,t,n,m,a[5005],b[5005];
long long dp[100005],ans,M=998244353;
struct node{
	double xing;
	long long id,yuan,xian; 
}c[5005];
bool cmp(node aa,node bb){
	if(aa.xing==bb.xing){
		if(aa.yuan==bb.yuan){
			return aa.id<bb.id;
		}
		else{
			return aa.yuan>bb.yuan;
		}
	}
	else{
		return aa.xing>bb.xing;
	}
}
void dfs(int cnt,int d){
	if(cnt==n+1){
		for(int i=1;i<=n;i++){
			c[i].xing=1.0*a[i]/b[i];
			c[i].id=i;
			c[i].yuan=a[i];
			c[i].xian=b[i];
		}
		sort(c+1,c+n+1,cmp);
		long long mm=0,ans1=0;
		for(int i=1;i<=n;i++){
			if(c[i].xian+mm<=m){
				mm+=c[i].xian;
				ans1+=c[i].yuan;
			}
		}
		long long ans2=0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=m;j>=c[i].xian;j--){
				dp[j]=max(dp[j],dp[j-c[i].xian]+c[i].yuan);
			}
		}
		ans2=dp[m];
		if(ans1==ans2){
			ans++;
			ans%=M;
		}
		return ;
	}
	for(int i=1;i<=2;i++){
		b[cnt]=i;
		dfs(cnt+1,i);
	}
	return ;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&cc,&t);
	if(cc<=5){
		while(t--){
			ans=0;
			scanf("%d%d",&n,&m);
			for(int i=1;i<=n;i++){
				scanf("%d",&a[i]);
			}
			dfs(1,0);
			printf("%lld\n",ans%M);
		}
	}
	return 0;
} 
