#include<bits/stdc++.h>
using namespace std;
long long n,t[10000005],w[10000005],bw[10000005],mxw[10000005],mnt[10000005],ans;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>t[i];
	for(int i=1;i<=n;i++)cin>>w[i];
	memset(mnt,127,sizeof(mnt));
	for(int i=n;i>=1;i--)mnt[i]=min(mnt[i+1],t[i]);mnt[0]=0;
	for(int i=n;i>=1;i--)bw[i]=bw[i+1]+w[i];
	for(int i=n;i>=1;i--)mxw[i]=max(mxw[i+1],bw[i]);
	for(int i=1;i<=n;i++)ans=ans+(mnt[i]-mnt[i-1])*max(0ll,mxw[i]);
	cout<<ans;
	return 0;
}
