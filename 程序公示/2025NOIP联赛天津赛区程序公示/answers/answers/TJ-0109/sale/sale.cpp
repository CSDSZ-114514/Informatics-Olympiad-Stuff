#include<bits/stdc++.h>
using namespace std;
#define ll long long

int gcd(int x, int y) {
    return y == 0 ? x : gcd(y, x % y);
}

ll gcd(ll x, ll y) {
    return y == 0 ? x : gcd(y, x % y);
}
const int P = 998244353;

int c,t,n,m,a[5005], b[5005], C[5005][5005];

struct qq{
    int x, y;
};

int fpow(int x,int y){
    int re = 1;
    while(y){
        if(y&1)re = 1ll *re * x % P;
        x = 1ll* x*x%P;
        y>>=1;
    }
    return re;
}

int main() {
    freopen("sale.in", "r", stdin);
    freopen("sale.out", "w", stdout);
    for(int i = 0; i<=5000;i++)C[i][i] = C[i][0] = 1;
    for(int i = 1;i<=5000;i++){
        for(int j = 1;j<i;j++)C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
    cin>>c>>t;
    for(int ii = 1;ii<=t;ii++){
        scanf("%d%d", &n,&m);
        for(int i = 1;i<=n;i++)scanf("%d", &a[i]), a[i] *= 2;
        sort(a + 1, a + n + 1);
        int ans = fpow(2, n);
        /*
        for(int i = 1;i<=n;i++){
            int cnt = 0;
            for(int j = 1;j<=n;j++){
                if(a[j] > a[i] / 2 && a[j] < a[i]){

                }
            }
            for(int j = 1;j<=cnt;j++){
                ans -= 1ll * C[cnt][j] * C[n - i][(m - 1) - (n - i)] % P;
            }
        }*/
        printf("%d\n", ans);
        /*
        for(int i = 1;i<(1<<n);i++){
            for(int j = 0;j<n;j++){
                if(i&(1<<j))b[j] = a[j] / 2;
                else b[j] = a[j];
            }
            sort(b + 1, b + n + 1);
            int nw = 1, lft = m;
            while(nw<=n && lft >= )
        }
        */
    }
    return 0;
}
/*

*/

