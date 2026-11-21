#include <bits/stdc++.h>
using namespace std;
long long n, m;
map<char, long long> mp;

string s, t[10000005];
long long tr[10000005][5], idx;
void insect(string s) {
    long long p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (tr[p][mp[s[i]]]) {
            p = tr[p][mp[s[i]]];
        } else {
            tr[p][mp[s[i]]] = ++idx;
            p = tr[p][mp[s[i]]];
        }
    }
}
long long ne[10000005];
void build() {
    queue<long long> q;
    for (int i = 1; i <= 4; i++) {
        if (tr[0][i])
            q.push(tr[0][i]);
    }
    while (!q.empty()) {
        long long u = q.front();
        q.pop();
        for (int i = 1; i <= 4; i++) {
            long long v = tr[u][i];
            if (v) {
                ne[v] = tr[ne[u]][i];
                q.push(v);
            } else {
                tr[u][i] = tr[ne[u]][i];
            }
        }
    }
}
bool vis[10000005];
void query(string s) {
    long long p = 0;
    for (int i = 0; i < s.size(); i++) {
        p = tr[p][mp[s[i]]];
        for (int j = p; j != 0; j = ne[j]) {
            vis[j] = 1;
        }
    }
}
long long mj(string s) {
    long long p = 0;
    for (int i = 0; i < s.size(); i++) {
        p = tr[p][mp[s[i]]];
        if (!vis[p])
            return i;
    }
    return s.size();
}
int main() {
    cin >> n >> m;
    mp['E'] = 1;
    mp['S'] = 2;
    mp['W'] = 3;
    mp['N'] = 4;
    cin >> s;
    for (int i = 1; i <= m; i++) {
        cin >> t[i];
        insect(t[i]);
    }
    build();
    query(s);
    for (int i = 1; i <= m; i++) {
        cout << mj(t[i]) << endl;
    }
    return 0;
}