#include<bits/stdc++.h>
using namespace std;
const long long N=1e5+5;
long long n,m,k,s,t;
struct ED{
	long long v,w;
};
vector<ED> e[N];
struct Node{
	long long u,dis;
	bool operator<(const Node p)const{
		return dis>p.dis; 
	} 
};
struct PDS{
	long long val,id;
	bool operator<(const PDS p)const{
		return val<p.val; 
	} 
};
PDS sds[N],sdt[N];
priority_queue<Node> q; 
long long ds[N],dt[N];
bool vis[N];
void dj(long long d[],long long s) { 
	for(int i=1;i<=n;i++)d[i]=1e18;
	for(int i=1;i<=n;i++)vis[i]=false;
	d[s]=0;q.push({s,0}); 
	while(!q.empty()) {
		Node h=q.top(); 
		q.pop();
		if(vis[h.u])continue;
		vis[h.u]=true; 
		for(auto t:e[h.u]){ 
			if(!vis[t.v]&&d[t.v]>d[h.u]+t.w) {
				d[t.v]=d[h.u]+t.w;
				q.push({t.v,d[t.v]}); 
			}
		}
	}
}
long long get_rank(long long sum){
    long long rank=0;
    for (int i=1;i<=n;++i){
    	PDS P={sum-sdt[i].val,0}; 
        rank+=upper_bound(sds+1,sds+1+n,P)-sds-1;
        for(auto p:e[sdt[i].id]){
        	if(ds[p.v]<=sum-sdt[i].val)rank--;
		}
    }
    return rank;
}
long long solve(long long k) {
    long long l=0,r=sdt[n].val+sds[n].val;
    while (l<r) {
        long long mid=(l+r)>>1;
        if(get_rank(mid)<k)l=mid+1;
		else r=mid;
    }
    return l;
}
 
int main(){
	freopen("bishop.in","r",stdin);
	freopen("bishop.out","w",stdout);
	cin>>n>>m>>k>>s>>t;
	for(int i=1;i<n;i++){
		long long u,v,w;
		cin>>u>>v>>w;
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}
	dj(ds,s);
	dj(dt,t);
	for(int i=1;i<=n;i++){
		sds[i]={ds[i],i};
		sdt[i]={dt[i],i};
	}
	sort(sds+1,sds+1+n);
	sort(sdt+1,sdt+1+n);
	cout<<min(solve(m+1)+k,min(solve(1)+(long long)1e9,ds[t]));
	return 0;
}
