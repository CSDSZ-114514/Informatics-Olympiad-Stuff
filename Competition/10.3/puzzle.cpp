#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long mt[105][105],s[105],t[105];
long long qpow(long long a,long long b) {
	long long ans=1;
	while(b){
		if(b%2==1)ans=ans*a%m;
		b>>=1;a= a*a%m;
	}
	return ans;
}
void gauss(){
	long long row=1;
	for(int col=1;col<=n;col++){
		long long zyh=-1;
		for(int i=row;i<=n;i++){
			if(mt[i][col]!=0){
				zyh=i;
				break;
			}
			
		}
		if(zyh==-1)continue;
		for(int i=1;i<=n+1;i++)swap(mt[row][i],mt[zyh][i]);
		long long zyn=qpow(mt[row][col],m-2);
		for(int i=1;i<=n+1;i++)mt[row][i]=(zyn*mt[row][i])%m;
		for(int i=1;i<=n;i++){
			if(i==row||mt[i][col]==0)continue;
			long long cs=mt[i][col];
			for(int j=1;j<=n+1;j++){
				mt[i][j]=(mt[i][j]-cs*mt[row][j])%m;
				mt[i][j]=(mt[i][j]%m+m)%m;
			}
		}
		row++;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		mt[i][i]=1;
		long long k;cin>>k;
		for(int j=1;j<=k;j++){
			long long v;cin>>v;
			mt[v][i]=1;
		}
	}
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)mt[i][n+1]=((t[i]-s[i])%m+m)%m;
	gauss();
	for(int i=1;i<=n;i++){
		bool all0=true;
		for(int j=1;j<=n;j++){
			if(mt[i][j]!=0)all0=false;
		}
		if(all0&&mt[i][n+1]!=0){
			cout<<"niuza";
			return 0;
		}
	}
	for(int i=1;i<=n;i++)cout<<mt[i][n+1]<<" ";
	cout<<endl;
	return 0;
}
