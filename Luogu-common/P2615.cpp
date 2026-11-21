#include<bits/stdc++.h>
using namespace std;
long long n,f[45][45];
void dd(long long k,long long lx,long long ly){
	if(k==n*n+1){
		return ;
	}
	if(lx==1&&ly!=n){
		f[n][ly+1]=k;
		dd(k+1,n,ly+1);
	}else if (lx!=1&&ly==n){
		f[lx-1][1]=k;
		dd(k+1,lx-1,1);
	}else if (lx==1&&ly==n){
		f[lx+1][ly]=k;
		dd(k+1,lx+1,ly);
	}
	else if (lx!=1&&ly!=n){
		if(f[lx-1][ly+1]==0){
			f[lx-1][ly+1]=k;
			dd(k+1,lx-1,ly+1);
		}else{
			f[lx+1][ly]=k;
			dd(k+1,lx+1,ly);
		}
	}else{
		cout<<"//////";
	}
}
int main(){
	cin>>n;

	f[1][n/2+1]=1;
	dd(2,1,n/2+1);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<f[i][j]<<" ";
		}
		cout<<endl;
	}
}
