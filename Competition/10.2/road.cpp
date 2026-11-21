#include<bits/stdc++.h>
using namespace std;
long long n,m,b;
long long f[1000005],d[1000005];
bool vis[1000005];
struct ED{
	long long v,w;
	
};
struct NODE{
	long long t,d,xl;
	bool operator<(const NODE x) const{
		return d > x.d; 
	} 
};
vector<ED> e[10000005]; 
void DJGUN(long long s,long long lim) {
	priority_queue<NODE> q; 
	for(int i=1;i<=n;i++)d[i]=1e18;
	for(int i=1;i<=n;i++)vis[i]=0;
	d[s]=0; q.push({s,0}); 
	while(!q.empty()) {
		NODE h=q.top(); 
		q.pop();
		if(vis[h.t])continue;
		if(d[h.t]>b)continue;
		vis[h.t]=true; 
		for(ED t: e[h.t]) { 
			if(f[t.v]>lim)continue;
			if(!vis[t.v]&&d[t.v]>d[h.t]+t.w) { 
				d[t.v]=d[h.t]+t.w;
				q.push({t.v,d[t.v]});
			}
		}
	}
}
bool check(long long mid){
	if(f[1]>mid||f[n]>mid)return false;
	DJGUN(1,mid);
	if(d[n]!=1e18&&d[n]<=b)return true;
	else return false;
}
int main(){
	cin>>n>>m>>b;
	for(int i=1;i<=n;i++)cin>>f[i];
	for(int i=1;i<=m;i++){
		long long x,y,z;cin>>x>>y>>z;
		e[x].push_back({y,z});
		e[y].push_back({x,z});
	}
	long long l=-1,r=1e18,ans=-1;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	if(ans==-1||ans==1000000000000000001){
		cout<<"AFK";
		return 0;
	}
	cout<<ans;
	return 0;
} 
