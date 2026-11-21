#include <bits/stdc++.h>
using namespace std;
int main() {
    long long n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        long long x;
        cin >> x;
        long long ans = 1e18;
            for (long long c = 0; c <= 400; c++) {
                for (long long a = 0; a <= c + 1; a++) {
                    long long dmg = a * (c + 1) - a * (a - 1) / 2;
                    if (dmg >= x){
                        ans = min(c + a, ans);
                        break;
                    }
                }
        }
        cout << ans << endl;
    }
    return 0;
}