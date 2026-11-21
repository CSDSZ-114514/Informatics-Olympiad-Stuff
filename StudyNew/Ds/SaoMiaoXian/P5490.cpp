#include<bits/stdc++.h>
using namespace std;
long long n;
struct SMX {
    long long x1, x2, y, tag;
};
SMX a[1000005];
bool cmp(SMX a, SMX b) { return a.y < b.y; }
struct XDS {
    long long l, r, cnt, len;
};
XDS tr[50000005];
long long b[1000005];
void build(long long p, long long l, long long r) { 
    tr[p] = {l, r, 0, 0}; 
    if(l==r){
        return ;
    }else{
        long long mid = (l + r) >> 1;
        build(2 * p, l, mid);
        build(2 * p + 1, mid + 1, r);
    }
}
void pushup(long long p){
    if(tr[p].cnt>0){
        tr[p].len = b[tr[p].r + 1] - b[tr[p].l];
    }else{
        tr[p].len = tr[2 * p].len + tr[2 * p + 1].len;
    }
}
void update(long long p,long long x,long long y,long long k){
    if(x<=tr[p].l&&tr[p].r<=y){
        tr[p].cnt += k;
        pushup(p);
        return;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if(x<=mid){
        update(2 * p, x, y, k);
    }
    if(y>mid){
        update(2 * p + 1, x, y, k);
    }
    pushup(p);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n;i++) {
        long long x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        a[2 * i] = {x1, x2, y1, 1};
        a[2 * i - 1] = {x1, x2, y2, -1};
        b[2 * i] = x1;
        b[2 * i - 1] = x2;
    }
    sort(b + 1, b + 1 + 2 * n);
    long long m = unique(b + 1, b + 1 + 2 * n) - (b + 1);
    sort(a + 1, a + 1 + 2 * n,cmp);
    build(1, 1, m-1);
    long long ans = 0;
    for (int i = 1; i <= 2*n;i++){
        long long l = lower_bound(b+1,b+1+m,a[i].x1) - b;
        long long r = lower_bound(b+1,b+1+m,a[i].x2) - b ;
        update(1, l, r - 1, a[i].tag);
        ans += tr[1].len * (a[i + 1].y - a[i].y);
    }
    cout << ans;
    return 0;
}