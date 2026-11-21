#include<bits/stdc++.h>
using namespace std;
long long n, m, s, t;
struct ED{
    long long u, v, w, c;
};
vector<ED> e;
vector<long long> h[100005];
void add(long long u,long long v,long long w,long long c){
    e.push_back({u,v,w,c});
    h[u].push_back(e.size() - 1);
    e.push_back({v,u,0,-1*c});
    h[v].push_back(e.size() - 1);
}
long long mf[100005],pre[100005],d[100005];
bool vis[100005];
bool spfa(){
    memset(mf, 0, sizeof(mf));
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));

    queue<long long> q;
    q.push(s);
    vis[s] = 1;
    mf[s] = 1e18;
    d[s] = 0;

    while(!q.empty()){
        long long u = q.front();
        q.pop();
        vis[u] = 0;
        for(auto t:h[u]){
            if(e[t].w&&d[e[t].v]>d[e[t].u]+e[t].c){
                d[e[t].v] = d[e[t].u] + e[t].c;
                mf[e[t].v] = min(mf[e[t].u], e[t].w);
                pre[e[t].v] = t;
                if(!vis[e[t].v]){
                    q.push(e[t].v);
                    vis[e[t].v] = 1;
                }
            }
        }
    }
    if(d[t]==0x3f3f3f3f3f3f3f3f)
        return false;
    else
        return true;
}
long long cost = 0, flow = 0;
void csf(){
    while(spfa()){
        long long v = t;
        while(v!=s){
            long long i=pre[v];
            e[i].w -= mf[t];
            e[i^1].w+=mf[t];
            v = e[i].u;
        }
        flow += mf[t];
        cost += mf[t] * d[t];
    }
}
int main(){
    cin>>n>>m>>s>>t;
    for (int i = 1; i <= m;i++){
        long long u, v, w, c;
        cin >> u >> v >> w >> c;
        add(u, v, w, c);
    }
    csf();
    cout << flow <<" "<< cost;
}