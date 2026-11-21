#include<bits/stdc++.h>
using namespace std;
long long n, m;
struct ed{
    long long v, w;
};
vector<ed> e[100005],e2[100005];




long long dfn[100005], tot, low[100005],scc[100005],cnt,siz[10005];
stack<long long> s;
void tarjan(long long u){
    dfn[u]=++tot;
    low[u] = tot;
    s.push(u);
    for(auto t:e[u]){
        if(!dfn[t.v]){
            tarjan(t.v);
            low[u] = min(low[u], low[t.v]);
        }else if(!scc[t.v]){
            low[u] = min(low[u], dfn[t.v]);
        }
    }
    if(dfn[u]==low[u]){
        cnt++;
        while(!s.empty()){
            long long t = s.top();
            s.pop();
            scc[t] = cnt;
            siz[cnt]++;
            if(t==u){
                break;
            }
        }
    }
}


struct Node{
	long long u, dis;
	bool operator<(const Node p) const{
		return dis > p.dis; 
	} 
};
priority_queue<Node> q;
long long d[100005];
bool vis[100005];
void dijkstra(int s) {
	for(int i=1; i<=n; i++) {
		d[i] = 1e18;
	}
	d[s] = 0; //起点设置为0 
	q.push({s, 0}); //起点和最短路 入队 
	
	while(!q.empty()) {
		Node h = q.top(); //取出队首元素，当前元素的d值发生变更，且最小 
		q.pop();
		if(vis[h.u]) {
			continue;
		}
		vis[h.u] = 1; //更新当前点计算出最短路 
		for(ed t: e2[h.u]) { //枚举u的所有出边 
			if(!vis[t.v] && d[t.v] > d[h.u] + t.w) { //如果v点经过u点的最短路径更短，则更新   
				d[t.v] = d[h.u] + t.w;
				q.push({t.v, d[t.v]}); //更新的点入队 
			}
		}
	}
}


int main(){
    cin>>n>>m;
    for (int i = 1; i <= m;i++){
        long long u, v, w;
        cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    for (int i = 1; i <= n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for (int i = 1; i <= n;i++){
        for(auto t:e[i]){
            if(scc[i]!=scc[t.v]){
                e2[scc[i]].push_back({scc[t.v],t.w});
            }
        }
    }
    dijkstra(scc[1]);
    cout << d[scc[n]];
}