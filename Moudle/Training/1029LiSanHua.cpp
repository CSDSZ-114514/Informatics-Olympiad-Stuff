#include <bits/stdc++.h>
using namespace std;
long long a[100005], b[100005];
int main() {
    long long T;
    cin >> T;
    while (T--) {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(b + 1, b + 1 + n);
        long long lst=unique(b + 1, b + 1 + n)-b-1;
        //cout << lst;
        for (int i=1; i <= n;i++){
            long long rk = lower_bound(b + 1, b + 1 + lst, a[i]) - b;
            cout << rk << " ";
        }
        cout << endl;
    }
    return 0;
}