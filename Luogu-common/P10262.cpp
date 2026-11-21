#include<bits/stdc++.h>
using namespace std;
long long p,f[1005],g[1005];
string str;
int main(){
	cin>>p>>str;
	long long sum=0;
	for(int i=1;i<=str.length();i++){
		int k=(str[i-1]-'0');f[k%p]++;
		for(int j=0;j<p;j++){
			f[(j*10+k)%p]+=g[j];
		}
		sum+=f[0];
		for(int j=0;j<p;j++){
			g[j]=f[j];f[j]=0;
		}
	}
	cout<<sum;
	return 0;
}
