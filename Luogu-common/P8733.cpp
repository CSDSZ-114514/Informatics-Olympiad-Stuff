#include<bits/stdc++.h>
using namespace std;
long long n,D,x[22],y[22];
double d[22][22],f[(1<<20)+5][21];
void floyd() {
	memset(d,127,sizeof(d));
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if((sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)))<=D){
				d[i][j]=(sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2)));
			}
		}
	}
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				d[i][j] = min(d[i][j],d[i][k]+d[j][k]); 
			}
		}
	}
}

int main(){
	cin>>n>>D;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
	}
	floyd();
	memset(f,127,sizeof(f));
	f[1][1]=0;
	for(int i=0;i<=(1<<n)-1;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if((j!=k)&&(i&1<<(j-1))&&(i&1<<(k-1))){
					f[i][j]=min(f[i][j],f[i^(1<<(j-1))][k]+d[k][j]);
				}
			}
		}
	}
	double ans=1e18;
	for(int i=1;i<=n;i++){
		ans=min(ans,f[(1<<n)-1][i]+d[i][1]);
	}
	cout<<fixed<<setprecision(2);
	cout<<ans;
}
