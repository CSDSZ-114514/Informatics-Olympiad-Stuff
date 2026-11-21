#include <bits/stdc++.h>
using namespace std;
long long n;
long long x, id[1005][1005],ne[1005][1005];
bool check(long long k){
    
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        int cur = i;
        for (int t = 0; t < 3; t++)
            if (x == t)
                id[i][t] = 0;
            else {
                id[i][t] = cur;
                cur += n;
            }
        for (int j = 1; j < n; j++)
            cin >> ne[i][j];
    }
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << r << '\n';
    return 0;
}