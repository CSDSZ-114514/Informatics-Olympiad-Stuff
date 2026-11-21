#include<bits/stdc++.h>
using namespace std;
struct NODE{
	long long v,w;
};
vector<NODE> mp[10005];queue<long long> q;
long long d[10005],vis[10005],cnt[10005];
long long n,v0;
void spfa(long long s){
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
				if(!vis[t.v]){
					q.push(t.v);
					vis[t.v]=1;
				}
			}
		}
	}
}
int main(){
	cin>>n>>v0;
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			int temp;
			if(scanf("%d",&temp)==1){
				mp[i].push_back({j,temp});
			}	
		}
	}
	spfa(v0);
	for(int i=1;i<=n;i++){
		if(i!=v0){
			cout<<"("<<v0<<" -> "<<i<<") = "<<d[i]<<endl;
		}
	}
}
