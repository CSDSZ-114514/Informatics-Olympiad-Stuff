#include<bits/stdc++.h>
using namespace std;
long long mp[1011][1011];
long long n,m;
long long d[100005],ans=1;
bool vis[100005];
const long long inf=1e12,mod = (1 << 31) - 1;
struct Node{
	long long  u, dis;
	bool operator<(const Node p) const{
		return dis > p.dis; 
	} 
};
struct Edge{
    long long v,w;
};
vector<Edge> e[100005];
priority_queue<Node> q;

void dijkstra(int s) {
	for(int i=1; i<=n; i++) {
		d[i] = inf;
	}
	d[s] = 0;
	q.push({s, 0}); 
	
	while(!q.empty()) {
		Node h = q.top(); 
		q.pop();
		if(vis[h.u]) {
			continue;
		}
		vis[h.u] = 1;
		for(Edge t: e[h.u]) {
			if(!vis[t.v] && d[t.v] > d[h.u] + t.w) {    
				d[t.v] = d[h.u] + t.w;
				q.push({t.v, d[t.v]}); 
			}
		}
	}
}
int main(){
    freopen("castle.in","r",stdin);
    freopen("castle.out","w",stdout);
    cin>>n>>m;
    memset (mp, 0x3f, sizeof (mp));
    for(int i=1;i<=m;i++){
        long long u,v,w;cin>>u>>v>>w;
        e[u].push_back ({v,w});
		e[v].push_back ({u,w});
        mp[u][v] = mp[v][u] = min (mp[u][v], w);
    }
    dijkstra(1);
    for(int i=2;i<=n;i++){
        long long sum=0;
        for(int j=1;j<=n;j++){
            if((d[j]+mp[i][j])==d[i]){
                sum++;
            }
        }
        if(sum>0)ans=(ans*sum)%mod;
    }
    cout<<ans;
}
