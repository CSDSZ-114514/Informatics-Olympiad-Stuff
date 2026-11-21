#include <bits/stdc++.h>
using namespace std;
struct LN {
    long long l, r;
    bool operator<(const LN x) const { return r < x.l; }
};
multiset<LN> se;
long long n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        char s;
        cin >> s;
        if (s == 'A') {
            long long l, r, cnt = 0;
            cin >> l >> r;
            cout << se.count({l,r}) << endl;
            se.erase({l, r});
            se.insert({l, r});
        } else {
            cout << se.size()<<endl;
        }
    }
    return 0;
}