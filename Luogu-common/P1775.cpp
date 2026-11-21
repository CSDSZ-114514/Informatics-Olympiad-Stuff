#include<bits/stdc++.h>
using namespace std;
int n,m[10005],f[10005][10005],s[10005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];s[i]=s[i-1]+m[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=1e9;
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	for(int len=2;len<=n;len++){
		for(int start=1;start+len-1<=n;start++){
			for(int k=start;k<start+len-1;k++){
				f[start][start+len-1]=min(f[start][k]+f[k+1][start+len-1]+s[start+len-1]-s[start-1],f[start][start+len-1]);
			}
		}
	}
	cout<<f[1][n];
}
