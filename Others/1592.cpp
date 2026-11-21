#include<bits/stdc++.h>
using namespace std;
int n,k;
long long cnt,q[10005],p[10005],f[15][105][2005];
int main(){
	cin>>n>>k;
	for(int i=0;i<(1<<n);i++){
		if(!(i&(i>>1))){
			q[++cnt]=i;
			for(int j=0;j<n;j++){
				if(1&i>>j){
					p[cnt]++;
				}
			}
			//cout<<"i:"<<i<<" :"<<p[cnt]<<endl;
		}
	}
	//cout<<"cnt:"<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		f[1][p[i]][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=k;j++){
			for(int a=1;a<=cnt;a++){
				for(int b=1;b<=cnt;b++){
					if(!(q[a]<<1&q[b])&&!(q[a]&q[b])&&!(q[a]>>1&q[b])&&j-p[b]>=0){
						f[i][j][a]+=f[i-1][j-p[a]][b];
					}
				}
			}
		}
	}
	long long sum=0;
	for(int i=1;i<=cnt;i++){
		sum+=f[n][k][i];
	}
	cout<<sum;
}
