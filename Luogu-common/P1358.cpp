#include<bits/stdc++.h>
using namespace std;
long long a[100005],c[100005][105];
void cnm(long long n,long long m){
	for(int i=0;i<=n;i++){
		c[i][0]=1;c[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=100;j++){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=10007;
		}
	}
}
int main(){
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	cnm(n,m);
	long long lst=n,ans=1;
	for(int i=1;i<=m;i++){
		ans*=c[lst][a[i]];
		ans%=10007;
		lst-=a[i];
	}
	cout<<ans;
}
