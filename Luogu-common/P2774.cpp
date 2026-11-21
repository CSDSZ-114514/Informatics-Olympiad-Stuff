#include<bits/stdc++.h>
using namespace std;
long long m, n,s,t,ans;
struct ED{
    long long u, v, w;
};
vector<ED> e;
vector<long long> h[100005];
long long dx[5] = {0, 1, -1, 0, 0};
long long dy[5] = {0, 0, 0, 1, -1};
long long tto(long long x, long long y) { return (x - 1) * n + y; }
void add(long long u,long long v,long long w){
    e.push_back({u,v,w});
    h[u].push_back(e.size() - 1);
    e.push_back({v, u, 0});
    h[v].push_back(e.size() - 1);
}
long long d[1000005];
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
                d[v] = d[u] + 1;
                q.push(v);
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
        if(d[v]==d[u]+1&&e[t].w>0){
            long long rmf = dfs(v, min(mf, e[t].w));
            e[t].w -= rmf;
            e[t ^ 1].w += rmf;
            mf -= rmf;
            sum += rmf;
            if(mf==0){
                break;
            }
        }
    }
    return sum;
}
int main(){
    cin>>m>>n;
    t = m * n + 1;
    for (int i = 1; i <= m;i++){
        for (int j = 1; j <= n;j++){
            long long p;
            cin >> p;
            ans += p;
            if((i+j)%2==0){
                add(s, tto(i, j), p);
                for (int k = 1; k <= 4;k++){
                    long long tx = i + dx[k];
                    long long ty = j + dy[k];
                    if(tx<=m&&tx>=1&&ty<=n&&ty>=1){
                        add(tto(i, j), tto(tx, ty) , 1e18);
                    }
                }
            }
            if((i+j)%2==1){
                add(tto(i, j), t , p);
            }
        }
    }
    long long flow = 0;
    while(bfs()){
        flow += dfs(s, 1e18);
    }
    cout << ans - flow;
}