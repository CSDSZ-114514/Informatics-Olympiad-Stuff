#include <bits/stdc++.h>
using namespace std;
long long a[100005],b[100005];
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
        sort(b + 1, b + n + 1);
        long long m=unique(b + 1, b + n + 1) - (b + 1);
        for(int i=1;i<=n;i++){
            long long id=lower_bound(b+1,b+m+1,a[i])-b;
            cout << id << " ";
        }
        cout << endl;
    }
}