#include <bits/stdc++.h>
using namespace std;
long long n;
string s[1000005],s2[1000005];
long long t[1000005][30], idx, cnt[1000005];
void insert(string s) {
    long long p = 0;
    for (int i = 0; i < s.size(); i++) {
        long long j = s[i] - 'a';
        if (t[p][j]) {
            p = t[p][j];
        } else {
            t[p][j] = ++idx;
            p = idx;
        }
    }
    cnt[p]++;
}
vector<long long> e[100005];
long long rd[100005];
bool check(string s) {
    for (int i = 0; i <= 25; i++) {
        e[i].clear();
    }
    memset(rd, 0, sizeof(rd));

    long long p = 0;
    for (int i = 0; i < s.size(); i++) {
        long long jj = s[i] - 'a';
        
        if (cnt[t[p][jj]] && i != s.size() - 1) {
            //cout << 1;
            return false;
        }
        
        for (int j = 0; j <= 25; j++) {
            if (j != jj && t[p][j]) {
                e[jj].push_back(j);
                rd[j]++;
            }
        }
        p = t[p][jj];
    }
    return true;
}
bool topo() {
    queue<long long> q;
    long long cntp = 0;
    for (int i = 0; i <= 25; i++) {
        if (rd[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        long long u = q.front();
        q.pop();cntp++;
        for (auto t : e[u]) {
            rd[t]--;
            if (rd[t] == 0) {
                q.push(t); 
            }
        }
    }
    if(cntp!=26){
        return false;
    }else{
        return true;
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        insert(s[i]);
    }
    long long a1 = 0;
    for (int i = 1; i <= n; i++) {
        if (check(s[i])) {
            
            if (topo()) {
                s2[++a1] = s[i];
            }
        }
    }
    cout << a1 << endl;
    for (int i = 1; i <= a1;i++){
        cout << s2[i] << endl;
    }
}