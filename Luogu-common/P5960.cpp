#include<bits/stdc++.h>
using namespace std;
struct NODE{
	int v,w;
};
vector<NODE> mp[10005];queue<long long> q;
int n,m;int c1,c2,y;long long d[10005],vis[10005],cnt[10005];
bool spfa(long long s){
	for(int i=1;i<=n;i++){
		d[i]=1e9;
	}
	d[s]=0;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(NODE t:mp[u]){
			if(d[t.v]>d[u]+t.w){
				d[t.v]=d[u]+t.w;
				cnt[t.v]=cnt[u]+1;
				if(cnt[t.v]>n){
					return false;
				}
				if(!vis[t.v]){
					q.push(t.v);
					vis[t.v]=1;
				}
			}
		}
	}
	return true;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c1>>c2>>y;
		mp[c2].push_back({c1,y});
	}
	for (int i=1;i<=n;i++){
		mp[9000].push_back({i,0});
	}
	if(spfa(9000)){
		for(int i=1;i<=n;i++){
			cout<<d[i]<<" ";
		}
	}else{
		cout<<"NO";
	}
	
}
