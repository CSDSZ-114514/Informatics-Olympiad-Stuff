#include <bits/stdc++.h>
using namespace std;
long long n, ans;
struct TW {
    long long o, i, b;
    bool operator<(TW x) const { return b > x.b; }
} tw[1000005];
multiset<long long> st;
int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> tw[i].o >> tw[i].i >> tw[i].b;
        ans += tw[i].i * tw[i].b;
        st.insert(tw[i].o);
    }
    sort(tw + 1, tw + 1 + n);
    for (int i = 1; i <= n; ++i) {
        auto it = st.lower_bound(tw[i].i);
        if (it != st.begin()) {
            ans -= (*--it) * tw[i].b;
            st.erase(it);
        }
    }
    cout << ans;
    return 0;
}