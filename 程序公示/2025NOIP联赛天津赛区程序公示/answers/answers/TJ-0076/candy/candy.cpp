//dp(j)={0<i<=n,dp(j)=max(dp(j),dp(j-a[i])+1)      Âò1¿Å   } 
//      {n<i<=2*n,dp(j)=max(dp(j),dp(j-k*a[i])+2*k)Âòk´Î2¿Å} 
#include<bits/stdc++.h>
using namespace std;
int n,a[2020],dp[10050];
int m;
void into(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int t;
		scanf("%d%d",&a[i],&t);
		a[i+n]=a[i]+t;
	}
}
void work(){
	
	for(int i=1;i<=2*n;i++){
		for(int j=m;j>=a[i];j--){
			for(int k=1;k*a[i]<=j;k++){
				if(j>=k*a[i]){
					if(i>n){
						dp[j]=max(dp[j],dp[j-k*a[i]]+2*k);
					}else dp[j]=max(dp[j],dp[j-a[i]]+1);
				}
			}
		}
	}
	printf("%d",dp[m]);
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	into();
	work();
	return 0;
}


