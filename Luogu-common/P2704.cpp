#include<bits/stdc++.h>
using namespace std;
long long m,n,ld[105],cnt,zt[2005],num[505],f[105][205][205],sum;

int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			char a=0;
			cin>>a;
			ld[i]=ld[i]<<1;
			if(a=='P'){
				ld[i]+=1;
			}
			if(a=='H'){
				ld[i]+=0;
			}
		}
	}
	//cout<<1;
	for(int i=0;i<(1<<m);i++){
		if(!(i&i>>2)&&!(i&i>>1)){
			zt[++cnt]=i;
			for(int j=0;j<m;j++){
				if(1&i>>j){
					num[cnt]++;
				}
			}
		}
	}
	//cout<<2;
	for(int i=1;i<=cnt;i++){
		if((ld[1]&zt[i])==zt[i]){
			for(int j=1;j<=cnt;j++){
				if(!(zt[i]&zt[j])){
					f[1][i][j]=num[i];
				}
			}
		}
	}
	//cout<<3;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=cnt;j++){
			for(int k=1;k<=cnt;k++){
				for(int d=1;d<=cnt;d++){
					if(!(zt[j]&zt[k])&&!(zt[j]&zt[d])&&!(zt[d]&zt[k])&&((ld[i]&zt[j])==zt[j])){
						f[i][j][k]=max(f[i-1][k][d]+num[j],f[i][j][k]);
					}
				}
			}
		}
	}
	//cout<<4;
	long long sum=0;
	for(int i=1;i<=cnt;i++){
		for(int j=1;j<=cnt;j++){
			sum=max(f[n][i][j],sum);
		}
	}
	cout<<sum;
	return 0;
}
