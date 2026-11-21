#include<bits/stdc++.h>
using namespace std;
long long n;
struct NODE{
	long long to,val;
};
vector<NODE> mp[10005];
long long d[10005];bool vis[10005];
void plm(long long s){
	for(int i=0;i<=n;i++){
		d[i]=1e9;
	}
	d[s]=0;
	for(int i=1;i<=n;i++){
		int u=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(d[j]<d[u])u=j;
		}
		vis[u]=true;
		for(NODE t:mp[u]){
			if(d[t.to]>t.val&&!vis[t.to]){
				d[t.to]=t.val;
			}
		}
	}
	
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int v=0;
			cin>>v;
			mp[i].push_back({j,v});
		}
	}
	plm(1);
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=d[i];
	}
	cout<<sum;
}
