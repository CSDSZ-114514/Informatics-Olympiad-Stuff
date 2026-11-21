#include <bits/stdc++.h>
using namespace std;
struct IO {
#define mxsz (1 << 21)
	char buf[mxsz], * p1, * p2;
	IO() : p1(buf), p2(buf) {}
	inline char gc() {
		if (p1 == p2) p2 = (p1 = buf) + fread(buf, 1, mxsz, stdin);
		return p1 == p2 ? ' ' : *p1++;
	}
	inline int read() {
		int r = 0; char c = gc(); bool rev = 0;
		while (c < '0' || c>'9') rev |= (c == '-'), c = gc();
		while (c >= '0' && c <= '9') r = r * 10 + (c ^ 48), c = gc();
		return rev ? ~r + 1 : r;
	}
} io;

const int MXN = 3e7 + 5, MOD = 993244853;
int t;
long long ans = 0, d[MXN], p = 131 ;
int min1 = 1e9, min2 = 1e9;
int main() {
    t = io.read();
    while (t--) {
        int n = io.read();
        int qzh = 0;
        for (int i = 1; i <= n; i++) {
            d[i] = io.read();
            qzh += d[i];
        }
        min1 = 1e9, min2 = 1e9;
        bool flag = true;
        for (int i = n; i >= 2; i--) {
            if (qzh > min1) {
                if (min2 != 1e9 && qzh > min2) {
                    flag = false;
                    break;
                } else {
                    min2 = qzh;
                }
            } else {
                min2 = min1;
                min1 = qzh;
            }
            qzh -= d[i];
        }
        if (flag) {
            if (d[1] > min1) {
                if (min2 != 1e9 && qzh > min2) {
                    flag = false;
                }
            }
        }

        int ans_i = flag ? 65537 : 13579;
        ans = (ans + p * ans_i) % MOD;
        p = p * 131 % MOD;
    }
    cout << ans;
    return 0;
}