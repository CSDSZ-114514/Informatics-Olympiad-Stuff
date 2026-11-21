#include<bits/stdc++.h>
using namespace std;
struct qj{
    long long l,r,maxv,maxr,maxl,sum;
}q[2000005];
long long a[2000005];
long long pushup(long long p){
    q[p].maxv=max({q[2*p].maxv,q[2*p+1].maxv,q[2*p].maxr+q[2*p+1].maxl});
    q[p].maxl=max(q[2*p].maxl,q[2*p].sum+q[2*p+1].maxl);
    q[p].maxr=max(q[2*p+1].maxr,q[2*p+1].sum+q[2*p].maxr);
    q[p].sum=q[2*p].sum+q[2*p+1].sum;
    return 0;
}
long long build(long long p,long long l,long long r){
    q[p].l=l;q[p].r=r;
    if(l==r){
        q[p].maxv=a[l];q[p].maxr=a[l];q[p].maxl=a[l];q[p].sum=a[l];
    }else{
        long long mid=(l+r)>>1;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        pushup(p);
    }
    return 0;
}
void update(long long p,long long k,long long d){
    if(q[p].l==q[p].r&&q[p].l==k){
        q[p].maxv=d;q[p].maxr=d;q[p].maxl=d;q[p].sum=d;
    }else{
        long long mid=(q[p].l+q[p].r)>>1;
        if(k<=mid){
            update(2*p,k,d);
        }else{
            update(2*p+1,k,d);
        }
        pushup(p);
    }
}
void pushup_t(qj &p,qj ls,qj rs){
    p.maxv=max({ls.maxv,rs.maxv,ls.maxr+rs.maxl});
    p.maxl=max(ls.maxl,ls.sum+rs.maxl);
    p.maxr=max(rs.maxr,rs.sum+ls.maxr);
    p.sum=ls.sum+rs.sum;
}
qj query(long long p,long long l,long long r){
    if(l<=q[p].l&&q[p].r<=r){
        return q[p];
    }else{
        long long mid=(q[p].l+q[p].r)>>1;
        if(l<=mid&&r>mid){
            qj res;
            pushup_t(res,query(2*p,l,r),query(2*p+1,l,r));
            return res;
        }else if(l<=mid){
            return query(2*p,l,r);
        }else{
            return query(2*p+1,l,r);
        }
    }
}
int main(){
    long long n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        long long d;cin>>d;
        if(d==1){
            long long a,b;cin>>a>>b;if(a>b)swap(a,b);
            cout<<query(1,a,b).maxv<<endl;
        }else{
            long long p,s;cin>>p>>s;
            update(1,p,s);
        }
    }
    return 0;
}