#include <bits/stdc++.h>
using namespace std;
string s, t;
deque<long long> sta;
long long ne[1000005], f[1000005];
string s2;
int main() {
    cin >> s >> t;
    s = " " + s;
    t = " " + t;
    ne[1] = 0;
    for (int i = 2, j = 0; i <= t.size() - 1; i++) {
        while (j && t[i] != t[j + 1]) {
            j = ne[j];
        }
        if (t[i] == t[j + 1]) {
            j++;
        }
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= s.size() - 1; i++) {
        sta.push_back(i);
        while (j && s[i] != t[j + 1]) {
            j = ne[j];
        }
        if (s[i] == t[j + 1]) {
            j++;
        }
        f[i] = j;
        if (j == t.size() - 1) {
            for (int k = 1; k <= t.size() - 1; k++) {
                sta.pop_back();
            }
            if (!sta.empty()) {
                j = f[sta.back()];
            } else {
                j = f[0];
            }
        }
    }
    while (!sta.empty()) {

        cout << s[sta.front()];
        sta.pop_front();
    }
    return 0;
}