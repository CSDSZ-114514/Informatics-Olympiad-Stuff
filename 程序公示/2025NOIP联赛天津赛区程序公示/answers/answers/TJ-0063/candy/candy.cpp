/*对于第i个物品，我选择j次，价值就是j，代价就是price(i,j)

f[i][j]表示前i个糖果，背包容量为j可获得的最大价值
01背包 
f[i][j] = max(f[i-1][j-price(i,k)] + k) 
*/


#include <iostream>
#include <cstdio>
using namespace std;
int f[10010][10010];
#define ll long long
int n,m;
ll x[100010],y[100010];
int price(int i,int j){
	if(j%2==0) return (j/2)*(x[i]+y[i]);
	else return (j/2)*(x[i]+y[i]) + x[i];
}
int main(){
	
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);

	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			for(int k=0;price(i,k)<=j;k++){
				f[i][j]=max(f[i][j], f[i-1][j-price(i,k)]+k);
			}
		}
	}
	printf("%d",f[n][m]);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
