#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct dj{
    long long l,r,sum,gcd;
}q[4000005];
long long a[1000005],d[1000005];
void pushup(long long p){
    q[p].sum=q[2*p].sum+q[2*p+1].sum;
    q[p].gcd=__gcd(q[2*p].gcd,q[2*p+1].gcd);
}
void build(long long p,long long l,long long r){
    q[p].l=l;q[p].r=r;
    if(q[p].l==q[p].r){
        q[p].sum=d[l];q[p].gcd=d[l];
    }else{
        long long mid=(q[p].l+q[p].r)>>1;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        pushup(p);
    }
}
void update(long long p,long long k,long long f){
    if(q[p].l==q[p].r&&q[p].r==k){
        q[p].sum+=f;
        q[p].gcd+=f;
    }else{
        long long mid=(q[p].l+q[p].r)>>1;
        if(k<=mid){
            update(2*p,k,f);
        }else{
            update(2*p+1,k,f);
        }
        pushup(p);
    }
}
void pushup_t(dj &p,dj ls,dj rs){
    p.sum=ls.sum+rs.sum;
    p.gcd=__gcd(ls.gcd,rs.gcd);
}
dj query(long long p,long long l,long long r){
    if(l<=q[p].l&&q[p].r<=r){
        return q[p];
    }else{
        long long mid=(q[p].l+q[p].r)>>1;
        if(l<=mid&&r>mid){
            dj res;
            pushup_t(res,query(2*p,l,r),query(2*p+1,l,r));
            return res;
        }else if(l<=mid){
            return query(2*p,l,r);
        }else{
            return query(2*p+1,mid+1,r);
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1];
    build(1,1,n+1);
    for(int i=1;i<=m;i++){
        char t;cin>>t;
        if(t=='C'){
            long long l,r,pd;cin>>l>>r>>pd;
            update(1, l, pd);
            update(1, r + 1, -pd);

        }
        if(t=='Q'){
            long long l,r;cin>>l>>r;
            if (l == r) {
                cout << abs(query(1,1,l).sum) << endl;
            } else {
                cout << abs(__gcd(query(1,1,l).sum ,query(1,l+1,r).gcd)) << endl;
            }
        }
    }
    return 0;
}