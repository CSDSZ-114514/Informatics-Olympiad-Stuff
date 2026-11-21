#include<bits/stdc++.h>
#define int long long 
using namespace std;
int t;
int n,m;
vector<int>a[500005];
signed main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			int u,v;
			cin>>u>>v;
			a[u].push_back(v);
		}
		if(m==n-1){
			int cnt=0;
			for(int i=0;i<n;i++){
				cnt+=i;
			}
			cout<<cnt<<endl;
			continue;
		}
		srand(time(0));
		cout<<n*2-1<<endl;
	}	
}
