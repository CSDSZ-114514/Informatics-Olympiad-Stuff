#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005],avg,s[10000005],ans;
int main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],avg+=a[i];
	avg/=n;
	for(int i=0;i<n;i++)s[i]=s[i-1]+a[i]-avg;
	sort(s,s+n);long long med=s[n/2];
	for(int i=0;i<n;i++)ans=ans+abs(s[i]-med);
	cout<<ans;
	return 0;
}
