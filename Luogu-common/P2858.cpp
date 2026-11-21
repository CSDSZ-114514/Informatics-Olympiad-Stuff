#include<bits/stdc++.h>
using namespace std;
int n,ans,v[2020],f[10005][10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		f[i][i]=v[i]*n;
	}
	for(int i=2;i<=n;i++){
		for(int l=1;l+i-1<=n;l++){
			int r=l+i-1;
			f[l][l+i-1]=max(f[l][r-1]+v[r]*(n-i+1),f[l+1][r]+v[l]*(n-i+1));
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
