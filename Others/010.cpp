#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,a[10005],f[10005][10005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<=n;i++){
		f[i][0]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<=a[i];k++){
				if(j>=k){
					f[i][j]+=f[i-1][j-k];
					f[i][j]%=1000007;
				}
			}
		}
	}
	cout<<f[n][m];
	return 0;
}
