#include <bits/stdc++.h>
using namespace std;
long long n, a[10000005], b[10000005];
stack<long long> s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        while (!s.empty() && a[s.top()] <= a[i]) {
            s.pop();
        }
        if (!s.empty())
            b[i] = s.top();
        s.push(i);
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    return 0;
}