#include <iostream>
#include <algorithm>
#define file_io(id) do { \
    freopen(id".in", "r", stdin); /*freopen(id".out", "w", stdout);*/ \
} while(false)
using namespace std;

const int MAXN = 1e5 + 10;
int n; long long m, ans;
int x[MAXN], y[MAXN], sum[MAXN];

int main() {
    file_io("candy");
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> x[i] >> y[i], sum[i] = x[i] + y[i];
    sort(sum + 1, sum + n + 1);
    sort(x + 1, x + n + 1);

    ans = (m / (1LL * sum[1])) * 2LL;
    long long lft = m % (1LL * sum[1]); int i = 1;
    while (lft > 0) {
        if (lft - x[i++] >= 0)
            ans++;
        lft -= x[i - 1];
    }

    cout << ans << endl;
    return 0;
}
