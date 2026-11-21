#include <bits/stdc++.h>
using namespace std;
long long n, m;
struct ED {
    long long u,v, w;
    bool operator<(const ED p) const { return w < p.w; }
};
vector<ED> e;
long long fa[100005];
long long query(long long a) {
    if (fa[a] == a) {
        return a;
    } else {
        return fa[a] = query(fa[a]);
    }
}
void heb(long long a, long long b) { fa[query(a)] = query(b); }

long long kruscal() {
    long long ans = 0,cnt=0;
    sort(e.begin(),e.end());
    for(auto t:e){
        if(query(t.u)!=query(t.v)){
            ans += t.w;
            heb(t.u, t.v);
            cnt++;
        }
    }
    if(cnt!=n-1)
        return -1;
    return ans;
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        e.push_back({x, y, z});
    }

    long long kr = kruscal();
    cout << (kr == -1 ? "orz" : to_string(kr));
    return 0;
}