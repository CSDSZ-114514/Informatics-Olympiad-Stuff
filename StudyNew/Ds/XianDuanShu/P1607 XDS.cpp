#include<bits/stdc++.h>
using namespace std;
long long k,n,c;
struct COW{
    long long s,e,m;
}b[100005];
bool cmp(COW x,COW y){
    return x.e < y.e;
}
struct J{
    long long l,r,sum,add,mx;
}q[400005];
long long a[400005];
long long pushup(long long p){
    q[p].sum=q[2*p].sum+q[2*p+1].sum;
    q[p].mx=max(q[2*p].mx,q[2*p+1].mx);
    return 0;
}
long long pushdown(long long p){
    if(q[p].add){
        q[2*p].sum+=(q[2*p].r-q[2*p].l+1)*q[p].add;
        q[2*p].mx+=q[p].add;
        q[2*p].add+=q[p].add;
        q[2*p+1].sum+=(q[2*p+1].r-q[2*p+1].l+1)*q[p].add;
        q[2*p+1].mx+=q[p].add;
        q[2*p+1].add+=q[p].add;
        q[p].add=0;
    }
    return 0;
}
long long build(long long p,long long l,long long r){
    q[p].l=l;q[p].r=r;
    q[p].mx=0;
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
        q[p].mx += k;
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
        return q[p].mx;
    }
    pushdown(p);
    long long mid=(q[p].l+q[p].r)>>1;
    long long res=0;
    if(l<=mid){
        res=max(res,query(2*p,l,r));
    }
    if(r>mid){
        res=max(res,query(2*p+1,l,r));
    }
    return res;
}
int main(){
    cin>>k>>n>>c;
    for(int i=1;i<=k;i++){
        cin>>b[i].s>>b[i].e>>b[i].m;
    }
    sort(b+1,b+1+k,cmp);
    long long ans=0;
    build(1,1,n);
    for(int i=1;i<=k;i++){
		long long l = b[i].s,r = b[i].e,m = b[i].m;
		int maxn = query(1,l,r-1);
        if(c-maxn>0){
            int chose =((c-maxn) < m)?(c-maxn):m;
		    ans += chose;
		    update(1,l,r-1,chose);
        }
	}
    cout<<ans;
    return 0;
}