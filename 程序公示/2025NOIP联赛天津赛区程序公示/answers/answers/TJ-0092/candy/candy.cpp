#include <bits/stdc++.h>
#define ll long long
#define MAXN 100010
using namespace std;
int n,price[MAXN][3];
ll m;
int res=-MAXN;
void dfs(ll cost,int num){
	res=max(res,num);
	
	for(int i=1;i<=n;i++){
		if(price[i][(price[i][2]+1)%2]+cost<=m){
			price[i][2]++;
			dfs(cost+price[i][price[i][2]%2],num+1);
			price[i][2]--;
		}
	}
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j>=0;j--){
			scanf("%d",&price[i][j]);
		}
	}
	
	if(n<=20){
		dfs(0,0);
	}else{//A
		int p[MAXN]={};
		for(int i=1;i<=n;i++){
			p[i]=price[i][0];
		}
		sort(p+1,p+1+n);
		ll cost=0;
		res=m/p[1];
	}
	printf("%d",res);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

