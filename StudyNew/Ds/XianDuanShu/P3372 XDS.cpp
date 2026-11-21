#include<bits/stdc++.h>
using namespace std;
struct J{
    long long l,r,sum,add;
}q[4000005];
long long a[4000005];
long long pushup(long long p){
    q[p].sum=q[2*p].sum+q[2*p+1].sum;
    return 0;
}
long long pushdown(long long p){
    if(q[p].add){
        q[2*p].sum+=(q[2*p].r-q[2*p].l+1)*q[p].add;
        q[2*p].add+=q[p].add;
        q[2*p+1].sum+=(q[2*p+1].r-q[2*p+1].l+1)*q[p].add;
        q[2*p+1].add+=q[p].add;
        q[p].add=0;
    }
    return 0;
}
long long build(long long p,long long l,long long r){
    q[p].l=l;q[p].r=r;
    if(l==r){
        q[p].sum=a[l];
    }else{
        long long mid=(l+r)>>1;
        build(2*p,l,mid);
        build(2*p+1,mid+1,r);
        pushup(p);
    }
    return 0;
}
long long update(long long p,long long l,long long r,long long k){
    if(l<=q[p].l&&q[p].r<=r){
        q[p].sum+=(q[p].r-q[p].l+1)*k;
        q[p].add+=k;
        return 0;
    }
    pushdown(p);
    long long mid=(q[p].l+q[p].r)>>1;
    if(l<=mid){
        update(2*p,l,r,k);
    }
    if(r>mid){
        update(2*p+1,l,r,k);
    }
    pushup(p);
    return 0;
}
long long query(long long p,long long l,long long r){
    if(l<=q[p].l&&q[p].r<=r){
        return q[p].sum;
    }
    pushdown(p);
    long long mid=(q[p].l+q[p].r)>>1;
    long long res=0;
    if(l<=mid){
        res+=query(2*p,l,r);
    }
    if(r>mid){
        res+=query(2*p+1,l,r);
    }

    return res;
}
int main(){
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        long long c;cin>>c;
        if(c==1){
            long long x,y,k;cin>>x>>y>>k;
            update(1,x,y,k);
        }else{
            long long x,y;cin>>x>>y;
            cout<<query(1,x,y)<<endl;
        }
    }
    return 0;
}