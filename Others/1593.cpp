#include<bits/stdc++.h>
using namespace std;
int m,n,ld[15],cnt,zt[2005],num[505],f[15][2005],sum;

int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			int a=0;
			cin>>a;
			ld[i]=ld[i]<<1;
			ld[i]+=a;
		}
	}
	for(int i=0;i<(1<<n);i++){
		if(!(i&i>>1)){
			zt[++cnt]=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		if((ld[1]&zt[i])==zt[i]){
			f[1][i]=1;
		}
	}
	for(int i=2;i<=m;i++){
		for(int a=1;a<=cnt;a++){
			for(int b=1;b<=cnt;b++){
				if((!(zt[a]&zt[b]))&&((ld[i]&zt[a])==zt[a])&&((ld[i-1]&zt[b])==zt[b])){
					f[i][a]+=f[i-1][b];
					f[i][a]%=100000000;
				}
			}
		}
	}
	for(int i=1;i<=cnt;i++){
		sum+=f[m][i];sum%=100000000;
	}
	cout<<sum;
	return 0;
}
