#include<bits/stdc++.h>
using namespace std;
long long a[1000005],s[10000005];
int main(){
	long long T;cin>>T;
	while(T--){
		long long n;
		cin>>n;
		map<long long,long long> mp;
		mp[0]++;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			s[i]=s[i-1]+a[i];
			//cout<<s[i]<<" ";
			mp[s[i]]++;
		}
		long long ans=-1e18;
		for(auto p:mp){
			ans=max(ans,p.second);
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
