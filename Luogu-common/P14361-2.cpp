#include <bits/stdc++.h>
using namespace std;
long long t;
struct ME {
    long long a;
    long long mx;
} me[10005][3];

priority_queue<long long> q;

int main() {
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> me[i][1].a >> me[i][2].a >> me[i][3].a;
            sort(me)
        }
        sort(me + 1, me + 1 + n, cmp);
        long long sum1 = 0, sum2 = 0, sum3 = 0;
        for (int i = 1; i <= n; i++) {
        }
    }
}