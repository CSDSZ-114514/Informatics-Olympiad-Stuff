#include<bits/stdc++.h>
using namespace std;
long long n,m,rd[100005],ans[100005];
vector<long long> me[100005],e[100005];
bool check(long long x){
	for(int i=1;i<=n;i++){
		e[i].clear();
		rd[i]=0;
	}
	for(int i=1;i<=x;i++){
		for(int j = 0; j + 1 < (int)me[i].size(); j++){
			e[me[i][j]].push_back(me[i][j+1]);
			rd[me[i][j+1]]++;
		}
	}
	queue<long long> q;
	for(int i=1;i<=n;i++){
		if(!rd[i])q.push(i);
	}
	long long cnt=0;
	while(!q.empty()){
		long long u=q.front();
		q.pop();++cnt;
		for(auto v:e[u]){
			
			if(--rd[v]==0)q.push(v);
		}
	}
	return cnt==n;
}
int main(){
	//freopen("s.out"."w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long mi;cin>>mi;
		for(int j=1;j<=mi;j++){
			long long p;cin>>p;
			me[i].push_back(p);
		}
	}
	long long l=0,r=m,ans1=0;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid))l=mid+1,ans1=mid;
		else r=mid-1;
	}
	for(int i=1;i<=n;i++){
		e[i].clear();
		rd[i]=0;
	}
	for(int i=1;i<=ans1;i++){
		for(int j = 0; j + 1 < (int)me[i].size(); j++){
			e[me[i][j]].push_back(me[i][j+1]);
			rd[me[i][j+1]]++;
		}
	}
	priority_queue<int, vector<int>, greater<int> > pq;
	for(int i=1;i<=n;i++){
		
		if(!rd[i])pq.push(i);
	}
	long long cnt=0;
	while(!pq.empty()){
		long long u=pq.top();
		pq.pop();
		ans[++cnt]=u;
		for(auto v:e[u]){
			if(--rd[v]==0)pq.push(v);
		}
	}
	for(int i=1;i<=cnt;i++)cout<<ans[i]<<" ";
	return 0;
}
