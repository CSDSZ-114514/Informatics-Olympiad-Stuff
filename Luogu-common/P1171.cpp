#include<bits/stdc++.h>
using namespace std;
long long n;long long ed[55][55];
long long zt[1005],cnt,num[1005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>ed[i][j];
		}
	}
	for(int i=0;i<(1<<n);i++){
		zt[++cnt]=i;
		for(int j=1;j<=n;j++){
			if(i<<j==1){
				num[cnt]++;
			}
		}
	}
	for(int i=1;i<=n;i++){//个数 20
		for(int j=1;j<=cnt;j++){//状态 400
			if(num[j]==i){
				
			}else{
				continue;
			}
		}
	}
}
