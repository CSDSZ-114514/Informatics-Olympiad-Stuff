#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long 
#define allin 2000
ull f[2005][2005],t,n,m,k,g[2005][2005];
int main(){
	cin>>t>>k;
	for(int i=0;i<=allin;i++){
		f[i][0]=1;
	}
	for(ull i=1;i<=allin;i++){
		for(ull j=1;j<=i;j++){
			f[i][j]=f[i-1][j]+f[i-1][j-1];
			f[i][j]%=k;
			if(f[i][j]%k==0){
				g[i][j]=1;
			}
			
		}
	}
	for(int i=1;i<=allin;i++){
		for(int j=1;j<=allin;j++){
			g[i][j]=g[i-1][j]+g[i][j-1]-g[i-1][j-1]+g[i][j];
		}
	}
	for(ull i=1;i<=t;i++){
		cin>>n>>m;
		cout<<g[n][m]<<endl;
		
	}
	
}
