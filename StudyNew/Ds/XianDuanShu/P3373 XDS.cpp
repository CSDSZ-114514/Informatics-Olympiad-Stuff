#include <bits/stdc++.h>
using namespace std;
struct J{
    long long l,r,sum,add,mul;
}tr[1000005];
long long a[1000005];
long long m;
long long pushup(long long p){
    tr[p].sum = (tr[p * 2].sum + tr[p * 2 + 1].sum) % m;
    return 0;
}
long long pushdown(long long p){
    if (tr[p].mul != 1 || tr[p].add != 0){
        long long len1 = tr[p * 2].r - tr[p * 2].l + 1;
        long long len2 = tr[p * 2 + 1].r - tr[p * 2 + 1].l + 1;
        tr[p * 2].sum = (tr[p * 2].sum * tr[p].mul + tr[p].add * len1) % m;
        tr[p * 2].mul = (tr[p * 2].mul * tr[p].mul) % m;
        tr[p * 2].add = (tr[p * 2].add * tr[p].mul + tr[p].add) % m;
        tr[p * 2 + 1].sum = (tr[p * 2 + 1].sum * tr[p].mul + tr[p].add * len2) % m;
        tr[p * 2 + 1].mul = (tr[p * 2 + 1].mul * tr[p].mul) % m;
        tr[p * 2 + 1].add = (tr[p * 2 + 1].add * tr[p].mul + tr[p].add) % m;
        tr[p].mul = 1;
        tr[p].add = 0;
    }
    return 0;
}
long long build(long long p,long long l,long long r){
    tr[p].l=l;tr[p].r=r;
    tr[p].mul=1;tr[p].add = 0;
    if(l==r){
        tr[p].sum=a[l];
    }else{
        long long mid=(l+r)>>1;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        pushup(p);
    }
    return 0;
}
long long updateadd(long long p,long long l,long long r,long long k){
    if(l <= tr[p].l && tr[p].r <= r){
        tr[p].add=(tr[p].add+k)%m;
        tr[p].sum=(tr[p].sum+(tr[p].r-tr[p].l+1)*k)%m;
        return 0;
    }
    pushdown(p);
    long long mid=(tr[p].l+tr[p].r)>>1;
    if(l<=mid){
        updateadd(2*p,l,r,k);
    }
    if(r>mid){
        updateadd(2*p+1,l,r,k);
    }
    pushup(p);
    return 0;
}
long long updatemul(long long p,long long l,long long r,long long k){
    if(l <= tr[p].l && tr[p].r <= r){
        tr[p].mul=tr[p].mul*k%m;
        tr[p].sum=tr[p].sum*k%m;
        tr[p].add=tr[p].add*k%m;
        return 0;
    }
    pushdown(p);
    long long mid=(tr[p].l+tr[p].r)>>1;
    if(l<=mid){
        updatemul(2*p,l,r,k);
    }
    if(r>mid){
        updatemul(2*p+1,l,r,k);
    }
    pushup(p);
    return 0;
}
long long query(long long p,long long l,long long r){
    if(l <= tr[p].l && tr[p].r <= r){
        return tr[p].sum;
    }
    pushdown(p);
    long long mid=(tr[p].l+tr[p].r)>>1;
    long long res=0;
    if (l <= mid) {
        res = (res + query(p * 2, l, r)) % m;
    }
    if (r > mid) {
        res = (res + query(p * 2 + 1, l, r)) % m;
    }

    return res%m;
}
int main(){
    long long n,q;cin>>n>>q>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1,1,n);
    for(int i=1;i<=q;i++){
        long long f;cin>>f;
        if(f==1){
            long long x,y,k;cin>>x>>y>>k;
            updatemul(1,x,y,k);
        }else if(f==2){
            long long x,y,k;cin>>x>>y>>k;
            updateadd(1,x,y,k);
        }else{
            long long x,y,k;cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
    }
}