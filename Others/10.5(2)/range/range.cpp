#include<bits/stdc++.h>
using namespace std;
long long T,n,a[100005],q,l,r,x;
unordered_map<long long ,vector<long long> > mp;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			long long t;cin>>t;
			mp[t].push_back(i);
		}
		cin>>q;
		for(int i=1;i<=q;i++){
			cin>>l>>r>>x;
			long long left=lower_bound(mp[x].begin(),mp[x].end(),l)-mp[x].begin();
			long long right=upper_bound(mp[x].begin(),mp[x].end(),r)-mp[x].begin();
			cout<<right-left<<endl;
		}
		
	}
} 
