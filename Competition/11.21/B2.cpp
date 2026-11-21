#include <bits/stdc++.h>
using namespace std;
long long t;
long long ans;
int main() {
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        string s = "+";
        for (int i = 1; i <= n - 1; i++) {
            s += "--+";
        }
        cout << s << endl;
        long long k;
        cin >> k;
        long long m = (k == 0) ? 0 : (k + 2) / 3;
        cout << n + m << endl;
    }
    return 0;
}