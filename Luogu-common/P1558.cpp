#include<bits/stdc++.h>
using namespace std;
long long l, t, o;
struct XDS{
    long long l, r, bts,add;
};
XDS tr[1000005];
long long getst(long long bts){
    long long cnt = 0;
    while(bts!=0){
        if(bts&1){
            cnt++;
        }
        bts >>= 1;
    }
    return cnt;
}
void pushdown (long long p){
    if(tr[p].add){
        tr[2 * p].bts = tr[p].add;
        tr[2 * p].add = tr[p].add;
        tr[2 * p+1].bts = tr[p].add;
        tr[2 * p+1].add = tr[p].add;
        tr[p].add = 0;
    }
}
void pushup (long long p){
    tr[p].bts=(tr[2*p].bts|tr[2*p+1].bts);
}
void build(long long p,long long l,long long r){
    tr[p]={l,r,1,0};
    if(l==r){
        return;
    }
    long long mid = (l + r) >> 1;
    build(2 * p, l, mid);
    build(2 * p + 1, mid + 1, r);
}
void update(long long p,long long x,long long y,long long k){
    if(x<=tr[p].l&&tr[p].r<=y){
        tr[p].bts = k;
        tr[p].add = k;
        return;
    }
    pushdown(p);
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if(x<=mid){
        update(2 * p, x, y, k);
    }
    if(y>mid){
        update(2 * p+1, x, y, k);
    }
    pushup(p);
}
long long query(long long p,long long x,long long y){
    if(x<=tr[p].l&&tr[p].r<=y){
        return tr[p].bts;
    }
    long long bts = 0;
    pushdown(p);
    long long mid = (tr[p].l + tr[p].r) >> 1;
    if(x<=mid){
        bts|= query(2 * p, x, y);
    }
    if(y>mid){
        bts|= query(2 * p+1, x, y);
    }
    return bts;
}
int main(){
    cin >> l >> t >> o;
    build(1, 1, l);
    
    for (int i = 1; i <= o;i++){
        char p;
        cin >> p;
        long long a, b, c;
        if(p=='C'){
            cin >> a >> b >> c;
            if(a>b){
                swap(a, b);
            }
            update(1, a, b, 1LL << (c - 1));
        }else{
            cin >> a >> b;
            if(a>b){
                swap(a, b);
            }
            cout << getst(query(1, a, b))<< endl;
        }
    }
    return 0;
}