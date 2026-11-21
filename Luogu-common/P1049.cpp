#include<bits/stdc++.h>
using namespace std;
int V,n,v[10005],f[10005][20005];
int main(){
	cin>>V>>n;
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=V;j++){
			if(j-v[i]>=0){
				f[i][j]=max(f[i-1][j-v[i]]+v[i],f[i-1][j]);
			}else{
				f[i][j]=f[i-1][j];
			}
			//cout<<f[i][j]<<endl;
		}
	}
	cout<<V-f[n][V];
	return 0;
}
