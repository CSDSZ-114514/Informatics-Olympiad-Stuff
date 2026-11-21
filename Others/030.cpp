#include<bits/stdc++.h>
using namespace std;	int n=0,m=0,t[1005][1005],f[1005][1005];
int main(){

	cin>>m>>n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=max(f[i-1][j],f[i][j-1])+t[i][j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<f[i][n]<<" ";
	}
	return 0;
}
