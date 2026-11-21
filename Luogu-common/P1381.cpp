#include <bits/stdc++.h>
using namespace std;
long long n, m,cnt;
map<string, long long> a, b;
string c[100005];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[s]++;
        
    }
    cin >> m;
    long long j = 0;
    long long a1=cnt, a2=1e18;
    long long sum = 0;
    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        b[c[i]]++;
        if(a[c[i]]&&b[c[i]]==1)
            cnt++;
    }
    if(cnt==0){
        cout<<0<<endl<<0;
        return 0;
    }
    b.clear();
    for (int i = 1; i <= m; i++) {
        while(j<m&&sum<cnt){
            j++;
            b[c[j]]++;
            if(b[c[j]]==1&&a[c[j]]){
                sum++;
            }
        }
        if(sum==cnt){
            a2 = min(a2, j - i + 1);
        }
        b[c[i]]--;
        if(b[c[i]]==0&&a[c[i]]){
            sum--;
        }
    }
    cout << cnt <<endl<< a2;
}