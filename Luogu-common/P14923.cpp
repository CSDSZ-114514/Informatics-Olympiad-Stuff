#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a, b;
long long c[100005];
struct EDGE {
    long long v, w;
};
vector<EDGE> e[100005];
long long d[100005];
bool vis[100005];
struct Node{
	int u, dis;
	bool operator<(const Node p) const{
		return dis > p.dis; 
	} 
};
priority_queue<Node> q; 
void djgun(long long s) {
    for (int i = 1; i <= n; i++) {
        d[i] = 1e18 + 5;
        vis[i] = 0;
    }
    d[s] = 0;
    q.push({s, 0});
    while (!q.empty()) {
        Node u = q.top();
        q.pop();
        if (vis[u.u]) {
            continue;
        }
        vis[u.u] = true; 
        for (auto t : e[u.u]) {
            if(!vis[t.v] && d[t.v] > d[u.u] + t.w) {   
				d[t.v] = d[u.u] + t.w;
				q.push({t.v, d[t.v]});
			}
        }
    }
}

int main() {
    cin >> n >> m;
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= m; i++) {
        long long u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    djgun(b);
    int sum=0;
    for(int i=1;i<=n;i++){
        if(d[i]<d[a]){
            sum+=c[i];
        }
    }
    cout << sum;
}