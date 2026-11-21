#include<bits/stdc++.h>
using namespace std;
long long f[55][55][55][55],a[55][55],m,n;
int main(){
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<i;k++){
				for(int p=j+1;p<=n;p++){
					f[i][j][k][p]=max({f[i-1][j][k-1][p],f[i-1][j][k][p-1],f[i][j-1][k-1][p],f[i][j-1][k][p-1]})+a[i][j]+a[k][p];
					//cout<<f[i][j][k][p]<<" ";
				}
			}
		}
	}
	
	
	
	cout<<f[m][n-1][m-1][n];
	return 0;
}
