#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5*1e4+5;
const bool debug = false;
struct candy{int a,w,idx;};

int ans,cnt;
int c,t,n,m;

int cmp(candy a,candy b){
    double rate1 = a.a/a.w;
    double rate2 = b.a/b.w;
    if(rate1!=rate2) return rate1 > rate2;
    if(a.a!=b.a) return a.a > b.a;
    return a.idx < b.idx;
}

int calc(candy a[]){
    int sum = 0;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++){
        if(m > a[i].w){
            sum += a[i].a;
            m -= a[i].w; 
        }
    }
    return sum;
}

void dfs(int p,candy a[]){
    if(p==n){
        int orisum = calc(a);
        if(debug){
            cout << "checking" << endl;
        }
        if(orisum > ans){
            cnt = 1;
            ans = orisum;
        }else if(orisum == ans){
            cnt++;
        }
        return;
    }
    for(int i=1;i<2;i++){
        a[p].w = i;
        dfs(p+1,a);
        a[p].w = 0;
    }
}
int main(){
    cin >> c >> t;
    freopen("sale.in","r",stdin);
    freopen("sale.out","w",stdout);
    while(t--){
        cin >> n >> m;
        ans = 0,cnt = 0;
        candy a[MAXN] = {{0,0,0}};
        for(int i=0;i<n;i++){
            cin >> a[i].a;
            a[i].idx = i;
        }
        if(debug){
        }
        if(c<=5){
            dfs(0,a);
            cout << cnt << endl;
            continue;
        }
        if(c==18){
            int tt = m - n;
            ans = 1;
            while(tt--){
                ans = (ans*2)%998224353;
            }
            cout << ans;
            continue;
        }
    }
}
