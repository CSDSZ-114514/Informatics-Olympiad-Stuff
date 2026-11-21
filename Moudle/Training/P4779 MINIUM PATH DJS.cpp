#include<bits/stdc++.h>
using namespace std;
long long n, m, s;
struct ED {
    long long v, w;
};
struct ND {
    long long u, w;
    bool operator<(const ND p) const{
		return w > p.w; 
	} 
};
priority_queue<ND> q;
vector<ED> e[100005];
long long d[100005];
bool vis[100005];
void djs(long long s){
    memset(d,0x3f,sizeof(d));
    d[s] = 0; 
    q.push({s, 0}); 
	while(!q.empty()) {
		auto h = q.top(); 
		q.pop();
		if(vis[h.u]) {
			continue;
		}
		vis[h.u] = 1; 
		for(auto t: e[h.u]) { 
			if(!vis[t.v] && d[t.v] > d[h.u] + t.w) { 
				d[t.v] = d[h.u] + t.w;
				q.push({t.v, d[t.v]}); 
			}
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    djs(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << " ";
    }
    return 0;
}