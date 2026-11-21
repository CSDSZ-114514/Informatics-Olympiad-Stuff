#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],f[10800];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		cin>>b[j];
	}
	memset(f,128,sizeof(f));
	f[1]=b[1];
	for(int i=2;i<=n+n;i++){
		for(int j=1;j<=m;j++){
			if(i-a[j]>0){
				f[i]=max(f[i-a[j]]+b[i],f[i]);
			}
		}
	}
	long long ans=-1e9;
	for(int i=n;i<=n+n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
