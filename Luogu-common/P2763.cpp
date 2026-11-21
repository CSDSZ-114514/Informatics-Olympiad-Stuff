#include <bits/stdc++.h>
using namespace std;
long long k, n,s,t;
struct ED {
    long long u, v, w;
};
vector<ED> e;
vector<long long> h[1000005];
void add(long long u, long long v, long long w) {
    e.push_back({u, v, w});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0});
    h[v].push_back(e.size() - 1);
}
long long mf[100005], pre[1000005];
bool bfs(){
    memset(mf, 0, sizeof(mf));
    queue<long long> q;
    q.push(s);
    mf[s] = 1e18;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        if(u==t)
            return true;
        for(auto t:h[u]){
            long long v = e[t].v;
            if(mf[v]==0&&e[t].w>0){
                mf[v] = min(mf[u], e[t].w);
                pre[v] = t;
                q.push(v);
            }
        }
    }
    return false;
}
int main() {
    long long m = 0;
    cin >> k >> n;
    for (int i = 1; i <= k; i++) {
        long long q;
        cin >> q;
        add(0, i, q);
        m += q;
    }
    t = k + n + 1;
    for (int i = 1; i <= n; i++) {
        long long p;
        cin >> p;
        for (int j = 1; j <= p; j++) {
            long long q;
            cin >> q;
            add(q, k + i, 1);
        }
        add(i + k, k + n + 1, 1);
    }
    long long flow = 0;
    while(bfs()){
        int v = t;
		while(v != s) { 
			int i = pre[v];
			e[i].w -= mf[t]; 
			e[i^1].w += mf[t]; 
			v = e[i].u;
		}
		flow += mf[t];	
    }
    if(flow<m){
        cout << "No Solution!";
        return 0;
    }
    for (int i = 1; i <= k;i++){
        cout << i << ": ";
        for(auto t:h[i]){
            if (e[t].v != 0 &&e[t].w == 0)
                cout << e[t].v-k << " ";
        }
        cout << endl;
    }
        return 0;
}