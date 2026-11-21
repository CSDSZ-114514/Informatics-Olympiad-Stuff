#include<bits/stdc++.h>
using namespace std;
long long a[105][105],b[105][105];
long long c[105][105];
long long m,n,p;
long long jzc(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p;j++){
			for(int k=1;k<=m;k++){
				c[i][j]+=(a[i][k]*b[k][j]);
			}
		}
	}
	return 0;
}
int main(){
	cin>>n>>m;cin>>p;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	cin>>p;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=p;j++){
			cin>>b[i][j];
		}
	}
	jzc();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=p;j++){
			cout<<c[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
