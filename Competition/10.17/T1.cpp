#include<bits/stdc++.h>
using namespace std;
long long n;
long long w[100005],d[100005];
long long sumw[100005],sumx[100005],x[100005];
long long ans=1e18;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>w[i]>>d[i];
	for(int i=1;i<=n;i++)x[i+1]=x[i]+d[i];
	for(int i=1;i<=n;i++){
		sumw[i]=sumw[i-1]+w[i];
		sumx[i]=sumx[i-1]+w[i]*x[i];
	}
	for(int j=1;j<=n;j++){
		for(int k=j+1;k<=n;k++){
			long long cost1=x[j]*sumw[j]-sumx[j];
            long long cost2=x[k]*(sumw[k]-sumw[j])-(sumx[k]-sumx[j]);
            long long cost3=x[n+1]*(sumw[n]-sumw[k])-(sumx[n]-sumx[k]);
            long long total=cost1+cost2+cost3;
            ans=min(total,ans);
		}
	}
	cout<<ans;
	return 0;
} 
