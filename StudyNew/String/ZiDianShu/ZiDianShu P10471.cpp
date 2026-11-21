#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 4e6 + 5;

int n, x, ans, idx, t[N][2];


void insert(int x) {
    long long p=0;
    for(int i=30;i>=0;i--){
        long long j=(x>>i)&1;
        if(t[p][j]==0){
            t[p][j]=++idx;
        }
        p=t[p][j];
    }
}
int query(int x) {
    int p=0,res=0;
    for(int i=30;i>=0;i--){
        long long j=(x>>i)&1;
        res*=2;
        if(t[p][!j]!=0){
            res|=1;
            p=t[p][!j];
        }else{
            p=t[p][j];
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    cin >> x;
    insert(x);
    
    for(int i = 2; i <= n; i++) {
        cin >> x;
        ans = max(ans, query(x)); 
        insert(x);  
    }
    
    cout << ans << endl;
    return 0;
}