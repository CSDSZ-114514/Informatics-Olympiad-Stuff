#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long s[1005], t[1005],g[70000005];
int mt[1005][1005];
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
bool gauss() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if(mt[j][j]!=0 && j<i) continue; 
			
			if(mt[j][i]!=0) {
				swap(mt[i], mt[j]);
				break;
			}
        }
        if(mt[i][i] == 0) {
            continue;
        }
        for (int j = 1; j <= n; j++) {
            if (i == j)
                continue;
            long long t = mt[j][i] * qpow(mt[i][i], m - 2, m) % m;
            for (int k = i; k <= n + 1; k++) {
                mt[j][k] = (mt[j][k] - mt[i][k] * t)% m;
                mt[j][k] = (mt[j][k] % m + m) % m;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (fabs(mt[i][i]) < 1e-5 && fabs(mt[i][n + 1]) >= 1e-5) {
            return 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        mt[i][n + 1] =(mt[i][n + 1]* qpow(mt[i][i], m - 2, m))% m;
        mt[i][n + 1] %= m;
        mt[i][i] = 1;
    }
    return 1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        long long k;
        cin >> k;
        mt[i][i] = 1;
        for (int j = 1; j <= k; j++) {
            long long c;
            cin >> c;
            mt[c][i] = 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for (int i = 1; i <= n; i++) {
        mt[i][n + 1] = t[i] - s[i];
    }
    if(gauss()){
        for (int i = 1; i <= n;i++){
            cout << mt[i][n + 1] << " ";
        }
    }else{
        cout << "niuza";
    }
        return 0;
}