#include<bits/stdc++.h>
using namespace std;
struct Node{
	long long v,w;
};
vector<Node> mp[10005];
long long n,m,d[100005];
bool vis[10005];

void dj(long long s){
	for(int i=0;i<=n;i++){
		d[i]=1e9;vis[i]=0;
	}
	d[s]=0;
	for(int i=1;i<=n;i++){
		long long minp=0;
		for(int j=1;j<=n;j++){
			if(vis[j]==0&&d[j]<d[minp]){
				minp=j;
			}
		}
		vis[minp]=1;
		for(Node t:mp[minp]){
			d[t.v]=min(d[minp]+t.w,d[t.v]);
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		mp[a].push_back({b,c});
		mp[b].push_back({a,c});
	}
	dj(1);
	if(d[n]!=1e9){
		cout<<d[n];
	}else{
		cout<<-1;
	}
}
