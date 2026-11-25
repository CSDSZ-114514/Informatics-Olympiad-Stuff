#include<bits/stdc++.h>
using namespace std;
int c[10005][10005];
const long long mod=998244353;
bool cmp(long long a,long long b){
	return a>b;
}
long long cc,t;
long long n,m,a[10005],pw[10005];
void init(){
	pw[0]=1;
	for(int i=0;i<=10000;i++)c[i][0]=c[i][i]=1;
	for(int i=1;i<=10000;i++)pw[i]=pw[i-1]*2%mod;
	for(int i=1;i<=10000;i++)for(int j=1;j<i;j++)c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
}
 
int main(){
	init();
	cin>>cc>>t;
	while(t--){
		cin>>n>>m;
		long long ans=0;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+1+n,cmp);
		for(int x=2;x<=n;x++){
			long long posz=x,bad=0;
			for(int y=1;y<x;y++){
				//cout<<y<<endl;
				if(2*a[x]<=a[y])continue;
				if(a[x]==a[y])continue;
				while(a[posz]>=a[y]-a[x]&&posz<=n)posz++;
				int k=m-y-1;
				if(k<0||k>x-2) continue;
				bad=(bad + 1LL*c[x-2][k]*pw[n-posz+1]%mod)%mod;
			}
			//cout<<smx<<endl;
			ans=(ans+bad)%mod;
		}
		cout<<(pw[n]-ans+mod)%mod<<endl;
	}
	return 0;
}
