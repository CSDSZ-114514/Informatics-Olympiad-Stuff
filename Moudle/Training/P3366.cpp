#include<bits/stdc++.h>
using namespace std;
long long n, m,fa[100005];
struct ED{
    long long w, v;
};
vector<ED> e[100005];
long long mintree(long long s){
    
}
int main() {
    cin >> n >> m;
    for (int i = 1; i <= m;i++) {
        long long x, y, z;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    for (int i = 1; i <= n;i++){
        fa[i] = i;
    }
    return 0; 
}