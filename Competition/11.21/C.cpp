#include <bits/stdc++.h>
using namespace std;
long long T;
long long ans;
long long t[100005];
int main() {
    cin >> T;
    while (T--) {
        long long n, x;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            long long a;
            cin >> a;
            t[i] = (a + x - 1) / x;
        }
        sort(t + 1, t + 1 + n);
        long long ans = 0;
        for (int i = 0; i <= n - 1;i++){
            ans = max(ans, t[i] - i);
        }
        cout << ans<<endl;
    }
}