#include <bits/stdc++.h>
using namespace std;
long long n, K, d[1000005],t[1000005],qzh[100005];
string s;
long long qpow(long long a, long long b, long long m) {
	long long ans = 1;
	while(b) {
		if(b%2==1) {
			ans = ans * a%m;
		}
		b/=2;
		a= a*a%m;
	}
	return ans;
}
int main() {
    cin >> n >> K;
    cin >> s;
    s = "$" + s;
    d[1] = 1;
    long long l = 1;
    long long r = 1;
    for (int i = 2; i <= n; i++) {
        if (i <= r) {
            d[i] = min(d[r - i + l], r - i + 1);
        }
        while (s[i - d[i]] == s[i + d[i]]) {
            d[i]++;
        }
        if (i + d[i] - 1 > r) {
            l = i - d[i] + 1;
            r = i + d[i] - 1;
        }
        t[2 * d[i] - 1]++;
    }
    long long sum = 0,ans=1;
    for (int i = n; i >=1;i--){
        if(i%2==0)
            continue;
        sum += t[i];
        ans *= qpow(i,min(K, sum),19930726)  ;
        ans %= 19930726;
        K -= sum;
        if(K<=0){
            break;
        }
    }
    if(K>0){
        cout << -1;
        return 0;
    }
    cout << ans;
    return 0;
}