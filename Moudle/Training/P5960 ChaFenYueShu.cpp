#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct ED {
    long long v, w;
};
vector<ED> e[100005];
long long d[100005];
bool vis[100005];
long long cnt[100005];
bool spfa(long long s) {
    queue<long long> q;
    q.push(s);
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    memset(cnt, 0, sizeof(cnt));
    vis[s] = 1;
    d[s] = 0;
    while(!q.empty()){
        long long u = q.front();
        q.pop();
        vis[u] = 0;
        for(auto t:e[u]){
            if(d[t.v]>d[u]+t.w){
                d[t.v] = d[u] + t.w;
                if(!vis[t.v]){
                    q.push(t.v);
                    vis[t.v] = 1;
                }
                cnt[t.v] = cnt[u] + 1; 
				if(cnt[t.v] > n) {
					return false;
				}
            }
        }
    }
    return true;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        e[0].push_back({i, 0});
    }
    for (int i = 1; i <= m; i++) {
        long long c1, c2, y;
        cin >> c1 >> c2 >> y;
        e[c2].push_back({c1, y});
    }
    if(spfa(0)){
        for (int i = 1; i <= n;i++){
            cout << d[i] << " ";
        }
    }else{
        cout << "NO";
    }
}