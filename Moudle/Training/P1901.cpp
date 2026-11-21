#include <bits/stdc++.h>
using namespace std;
long long n,h[1000005],v[1000005],t[10000005];
stack<long long> s;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i] >> v[i];
    }
    for (int i = 1; i <= n;i++){
        while(!s.empty()&&h[s.top()]<=h[i]){
            s.pop();
        }
        if(!s.empty()){
            t[s.top()] += v[i];
        }
        s.push(i);
    }
    while(!s.empty()){
        s.pop();
    }
    for (int i = n; i >= 1;i--){
        while(!s.empty()&&h[s.top()]<=h[i]){
            s.pop();
        }
        if(!s.empty()){
            t[s.top()] += v[i];
        }
        s.push(i);
    }
    long long ans = -1e9;
    for (int i = 1; i <= n;i++){
        ans = max(t[i], ans);
    }
    cout << ans;
}