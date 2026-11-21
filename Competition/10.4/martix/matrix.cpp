#include<bits/stdc++.h>
using namespace std;
long long d[1000005],mf[1000005],pre[1000005],a[105][105];
long long n,k;
bool vis[1000005]; 
long long s,t;
struct ED{
	long long u,v,w,c;
};
vector<ED> e;
vector<long long> h[1000005];
queue<long long> q;
long long tt1(long long x,long long y){
	return (x-1)*n+y;
}
void adeg(long long u,long long v,long long w,long long c){
	e.push_back({u,v,w,c});
	h[u].push_back(e.size()-1);
	e.push_back({v,u,0,-c}); 
	h[v].push_back(e.size()-1); 
}
void adg(long long x1,long long y1){
	adeg(tt1(x1,y1),n*n+tt1(x1,y1),1,-1*a[x1][y1]);
	adeg(tt1(x1,y1),n*n+tt1(x1,y1),k-1,0);
}
bool spfa(){
	memset(d,0x3f,sizeof(d));
	memset(mf,0,sizeof(mf));
	d[s]=0;
	vis[s]=1;
	mf[s]=1e18;
	q.push(s); 
	while(!q.empty()) {
		long long u=q.front();
		q.pop();
		vis[u]=0;
		for(auto i:h[u]) {
			long long v=e[i].v;			
			if(d[v]>d[u]+e[i].c&&e[i].w) { 
				d[v]=d[u]+e[i].c;  
				pre[v]=i; 
				mf[v]=min(mf[u],e[i].w); 
				if(!vis[v]){
					vis[v]=true;
					q.push(v);
				}
			}
		}
	}
	return mf[t]>0;
}

int main(){
	freopen("martix.in","r",stdin);
	freopen("martix.out","w",stdout);
	cin>>n>>k;
	s=tt1(1,1);
	t=n*n+tt1(n,n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			adg(i,j);
			if(i<n)adeg(n*n+tt1(i,j),tt1(i+1,j),k,0);
			if(j<n)adeg(n*n+tt1(i,j),tt1(i,j+1),k,0);
		}
	}
	long long flow=0,sum=0; 
	while(spfa()) {
		long long v=t; 
		while(v!=s){
			long long i=pre[v];
			e[i].w-=mf[t]; 
			e[i^1].w+=mf[t];
			v=e[i^1].v;
		}
		flow+=mf[t]; 
		sum+=d[t]*mf[t]; 
	}
	cout<<-sum; 
	
	return 0;
}
