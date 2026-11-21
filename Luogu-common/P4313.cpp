#include <bits/stdc++.h>
using namespace std;
long long n, m, s, t, cnt;
struct ED {
    long long u, v, w;
};
vector<ED> e;
vector<long long> h[1000005];
long long tto(long long x, long long y) { return x + n * (y - 1); }
void add(long long u, long long v, long long w) {
    e.push_back({u, v, w});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0});
    h[v].push_back(e.size() - 1);
}
long long dx[5] = {0, 1, -1, 0, 0};
long long dy[5] = {0, 0, 0, 1, -1};
long long d[100005];
bool bfs(){
    queue<long long> q;
    memset(d, 0, sizeof(d));
    q.push(s);
    d[s] = 1;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        if(u==t)
            return true;
        for(auto t:h[u]){
            long long v = e[t].v;
            if(d[v]==0&&e[t].w>0){
                q.push(v);
                d[v] = d[u] + 1;
            }
        }
    }
    return false;
}
long long dfs(long long u,long long mf){
    if(u==t){
        return mf;
    }
    long long sum = 0;
    for(auto t:h[u]){
        long long v = e[t].v;
        if(d[v]>d[u]&&e[t].w){
            long long rmf = dfs(v, min(mf, e[t].w));
            e[t].w -= rmf;
            e[t ^ 1].w += rmf;
            mf -= rmf;
            sum += rmf;
            if(mf == 0) {
				break;
			}
        }
    }
    return sum;
}
int main() {
    long long ans = 0;
    cin >> n >> m;
    t = n * m + 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long p;
            cin >> p;
            add(s, tto(i, j), p);
            ans += p;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long p;
            cin >> p;
            add(tto(i, j), t, p);
            ans += p;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long p;
            cin >> p;
            ans += p;
            ++cnt;
            add(s, n*m+cnt+1 , p);
            add(n*m+cnt+1, tto(i, j), 1e18);
            for (int k = 1; k <= 4;k++){
                long long tx = i + dx[k];
                long long ty = j + dy[k];
                if(tx<=n&&tx>=1&&ty<=m&&ty>=1){
                    add(n*m+cnt+1, tto(tx, ty), 1e18);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            long long p;
            cin >> p;
            ans += p;
            ++cnt;
            add(n*m+cnt+1, t, p);
            add(tto(i, j), n*m+cnt+1 , 1e18);
            for (int k = 1; k <= 4;k++){
                long long tx = i + dx[k];
                long long ty = j + dy[k];
                if(tx<=n&&tx>=1&&ty<=m&&ty>=1){
                    add(tto(tx, ty), n*m+cnt+1 , 1e18);
                }
            }
        }
    }
    long long flow = 0;
    while(bfs()){
        flow += dfs(s,1e18);
    }
    cout << ans - flow;
    return 0;
}