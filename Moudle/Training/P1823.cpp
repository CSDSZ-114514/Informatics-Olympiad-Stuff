#include <bits/stdc++.h>
using namespace std;
stack<pair<long long, long long>> s;
long long n;
int main(void) {
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        int h;
        cin >> h;
        pair<int, int> p(h, 1);
        while(!s.empty() && s.top().first <= h) {
            ans += s.top().second;
            if (s.top().first == h)
                p.second += s.top().second;
            s.pop();
        }
        if (!s.empty())
            ++ans;
        s.push(p);
    }
    cout << ans << endl;
    return 0;
}
