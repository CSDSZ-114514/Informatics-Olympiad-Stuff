#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		int ls,ans=0,maxx=0,sma=0;
		for(int i=0;i<n-1;i++){
			cin>>ls;
			ans+=ls;
			if(ls>maxx){
				sma=maxx;
				maxx=ls;
			}
		}
		cout<<ans+n%m+maxx-sma<<endl;
	}
	return 0;
} 
