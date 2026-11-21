#include<bits/stdc++.h>
using namespace std;
long long c[105][105],sumc[105][105];
int main(){
	for(int i=0;i<=32;i++){
		c[i][0]=1;
	} 
	for(int i=1;i<=32;i++){
		for(int j=1;j<=i;j++){
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		}
	}
	for(int i=0;i<=32;i++){
		sumc[i][0]=1;
		for(int j=1;j<=i;j++){
			sumc[i][j]=sumc[i][j-1]+c[i][j];
		}
	}
	long long n,l,k;
	cin>>n>>l>>k;
	string ans="";
	for(int i=0;i<n;i++){
		long long r=n-i-1,ll=min(r,l);
		long long cnt=sumc[r][ll];
		if(k<=cnt){
			ans+='0';
		}
		if(k>cnt){
			k=k-cnt;
			l--;
			ans+='1';
		}
	}
	cout<<ans;
	return 0;
}
