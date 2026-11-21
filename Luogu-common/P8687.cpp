#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long v[105],f[1<<20];
int main(){
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			int t;
			cin>>t;
			v[i]|=1<<(t-1);
		}
	}
	memset(f,127,sizeof(f));
	f[0]=0;
	for(int i=0;i<=((1<<m)-1);i++){
		for(int j=1;j<=n;j++){
			f[i|v[j]]=min(f[i]+1,f[i|v[j]]);
		}
	}
	if(f[(1<<m)-1]<1e9){
		cout<<f[(1<<m)-1];
	}else{
		cout<<-1;
	}
}
