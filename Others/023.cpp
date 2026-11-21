#include<bits/stdc++.h>
using namespace std;
int a[10005][10005],n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[j][i];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<endl;
		for(int j=n;j>=1;j--){
			cout<<a[i][j]<<" ";
		}
	}
	
}
