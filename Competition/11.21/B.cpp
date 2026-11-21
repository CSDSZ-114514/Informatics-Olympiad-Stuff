#include <bits/stdc++.h>
using namespace std;
long long t;
long long ans;
int main() {
    cin >> t;
    while (t--) {
        long long x, y, m;
        cin >> x >> y >> m;
        ans = x + y;
        string s;
        cin >> s;
        for (int i = 1; i <= m; i++) {
            if (x == 0 && y == 0)
                break;
            if (s[i - 1] == '+') {
                if (y > 0) {
                    y++;
                } else {
                    x--;
                    y++;
                }
            } else {
                if (y >= 2) {
                    y--;
                    x++;
                } else if (x > 0) {
                    x--;
                } else {
                    y--;
                    x++;
                }
            }
            ans = max(ans, x+y);
        }
        cout << ans << endl;
    }
    return 0;
}