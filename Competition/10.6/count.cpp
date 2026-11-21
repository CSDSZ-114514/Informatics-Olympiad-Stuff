#include<bits/stdc++.h>
using namespace std;
long long n,rd[10000005],mult[10000005];
long long m=1e9;
int main(){	
	cin>>n;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<n;i++){
		long long u,v;
		cin>>u>>v;
		rd[u]++;rd[v]++;
	}
	mult[0]=1;mult[1]=1;
	for(int i=2;i<=n+22;i++)mult[i]=i*mult[i-1]%(m);
	long long ans=1;
	for(int i=1;i<=n;i++)ans=ans*mult[rd[i]-1]%(m);
	cout<<(ans*(2*n-2))%m;
	return 0;
}
