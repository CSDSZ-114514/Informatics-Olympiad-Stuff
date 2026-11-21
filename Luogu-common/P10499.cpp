#include <bits/stdc++.h>
using namespace std;
long long k;
long long s[1000005], t[1000005];
long long a[1005][1005];
long long n, cnt;
bool gauss() {
    for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			if(a[j][j] != 0 && j<i) continue;
			
			if(a[j][i] != 0 ){
				swap(a[i], a[j]);
				break; 
			}
		}
		
		if(a[i][i]==0){
			continue;
		}
		
		for(int j=1; j<=n; j++) {
			if(i==j) continue;
			
			if(a[j][i]) { 
				for(int k=i; k<=n+1; k++) { 
					a[j][k]^=a[i][k];
				}
			}			
		}
	}
    for (int i = 1; i <= n; i++) {
        if (fabs(a[i][i]) < 1e-5 && fabs(a[i][n + 1]) >= 1e-5) {
            return 0;
        }
        if (a[i][i] == 0) {
            cnt++;
        }
    }
    return 1;
}
int main() {
    cin >> k;
    while (k--) {
        memset(a, 0, sizeof(a));
        cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> t[i];
        }
        while (true) {
            long long u, v;
            cin >> u >> v;
            if (!u && !v)
                break;
            a[v][u] = 1;
        }
        for (int i = 1; i <= n; i++) {
            a[i][i] = 1;
            a[i][n + 1] = t[i] ^ s[i];
        }

        if (!gauss()) {
            cout << "Oh,it's impossible~!!" << endl;
        } else {
            cout << (1 << cnt) << endl;
        }
    }

    return 0;
}