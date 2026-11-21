#include<bits/stdc++.h>
using namespace std;	
int n;int f[10][1000005],a[1000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(f,127,sizeof(f));
	f[0][0]=0;f[1][0]=0;f[2][0]=0;
	for(int j=1;j<=n;j++){
		f[0][j]=min({f[0][j-1],f[1][j-1],f[2][j-1]})+1;
		if(a[j]==1){
			f[1][j]=min({f[0][j-1],f[2][j-1]});
		}
		if(a[j]==2){
			f[2][j]=min({f[0][j-1],f[1][j-1]});
		}
		if(a[j]==3){
			f[1][j]=min({f[0][j-1],f[2][j-1]});
			f[2][j]=min({f[0][j-1],f[1][j-1]});
		}
	}
	cout<<min({f[0][n],f[1][n],f[2][n]});
}
