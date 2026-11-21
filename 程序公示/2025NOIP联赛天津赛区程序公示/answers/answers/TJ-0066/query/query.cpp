#include<iostream>
#include<cstdlib>
using namespace std;
const int MAXN = 5e4;
const int MAXQ = 1024;
const int INF = -1e9;
int a[MAXN+5];
int n,q,l,r,sum = 0;
int pre[MAXN+5],suf[MAXN+5];
int anss[MAXN+5];

inline int value(int l_,int r_){
    return sum-pre[l_-1]-suf[r_+1];
}

int ans(){
    int res = 0;
    for(int i=1;i<=n;i++){
        res ^= i*anss[i];
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        sum += a[i];
        pre[i] = sum;
    }
    suf[n] = a[n];
    for(int i=n-1;i>0;i--){
        suf[n] = suf[n+1]+a[i];
    }
    cin >> q;
    while(q--){
        cin >> l >> r;
        fill(anss,anss+MAXN+5,INF);
        for(int i=1;i<=n;i++)
        for(int length = l;length<=r;length++){
            for(int start=max(1,i-length+1);start<=i&&start+length<=n;start++){
                anss[i] = min(anss[i],value(start,start+length));
            }
        }
        cout << ans() << "\n";
    }

    return 0;
}













