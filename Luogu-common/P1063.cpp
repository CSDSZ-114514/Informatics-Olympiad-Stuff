#include<bits/stdc++.h>
using namespace std;
int n,a[10005],f[10005][10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];a[i+n]=a[i];
	}
	n*=2;
	for(int i=2;i<=n;i++){
		for(int j=1;j+i-1<=n;j++){
			for(int k=j;k<j+i-1;k++){
				f[j][j+i-1]=max(f[j][k]+f[k+1][i+j-1]+a[j]*a[k+1]*a[j+i],f[j][j+i-1]);
			}
		}
	}
	int mxsm=0;
	for(int i=1;i<=n/2;i++){
		mxsm=max(f[i][i+n/2-1],mxsm);
	}
	cout<<mxsm;
}
