#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],sum,maxsum,s[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		//cout<<s[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum=s[i-1]+s[n]-s[j]+j-i+1-s[j]+s[i-1];
			maxsum=max(sum,maxsum);
		}
	}
	cout<<maxsum;
}
