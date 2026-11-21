#include <bits/stdc++.h>
using namespace std;
long long T;
int s1[100005], s2[100005], t1[100005], t2[100005];
long long cnt1, cnt2, scn1[100005][5], scn2[100005][5], pos1[100005], pos2[100005], ans;
int main() {
    cin >> T;
    long long n;
    while (T--) {
        cin >> n;
        s1[0] = 1e18;
        s2[0] = 1e18;
        for (int i = 1; i <= n; i++) {
            cin >> s1[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> s2[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> t1[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> t2[i];
        }
        for (int i = 1; i <= n; i++) {
            if (t1[i] != t1[i - 1]) {
                pos1[i] = ++cnt1;
            } else {
                pos1[i] = pos1[i - 1];
            }
            scn1[cnt1][s1[i] - '0']++;
        }
        for (int i = 1; i <= n; i++) {
            if (t2[i] != t2[i - 1]) {
                pos2[i] = ++cnt2;
            } else {
                pos2[i] = pos2[i - 1];
            }
            scn2[cnt2][s2[i] - '0']++;
        }
        for (int i = 1; i <= n; i++) {
            if (t1[i] == '0' && t2[i] == '0') {
                if (s1[i] == s2[i])
                    ans++;
            } else if (t1[i] == '0') {
                if (scn2[pos2[i]][s1[i] - '0'] > 0) {
                    scn2[pos2[i]][s1[i] - '0']--;
                    ans++;
                }
            } else if (t2[i] == '0') {
                if (scn1[pos1[i]][s2[i] - '0'] > 0) {
                    scn1[pos1[i]][s2[i] - '0']--;
                    ans++;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (t1[i] == '0' || t2[i] == '0')
                continue;
            if (scn1[pos1[i]][1] > 0 && scn2[pos2[i]][1] > 0) {
                scn1[pos1[i]][1]--;
                scn2[pos2[i]][1]--;
                ans++;
            } else if (scn1[pos1[i]][0] > 0 && scn2[pos2[i]][0] > 0) {
                scn1[pos1[i]][0]--;
                scn2[pos2[i]][0]--;
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}