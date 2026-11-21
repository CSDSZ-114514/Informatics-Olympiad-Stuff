#include<bits/stdc++.h>
#define endl '\n' 
using namespace std;
#define ls x<<1
#define rs x<<1|1
const int N=3e4+5;
class SGT{
    const int INF=0x3f3f3f3f;
    int tr[N],tag[N];
public:
    void init(){
        memset(tr,-127,sizeof tr);
        memset(tag,-127,sizeof tag);
    }
    void pushdown(int x,int nl,int nr){
        if(nl==nr)
            return;
        tag[ls]=max(tag[ls],tag[x]),tag[rs]=max(tag[rs],tag[x]);
        tr[ls]=max(tr[ls],tag[x]),tr[rs]=max(tr[rs],tag[x]);
        tag[x]=-INF;
    }
    void adt(int x,int nl,int nr,int L,int R,int val){
        if(L<=nl&&nr<=R){
            tr[x]=max(tr[x],val);
            tag[x]=max(tag[x],val);
            return;
        }
        int mid=(nl+nr)>>1;
        pushdown(x,nl,nr);
        if(L<=mid)  adt(ls,nl,mid,L,R,val);
        if(R>mid)   adt(rs,mid+1,nr,L,R,val);
    }
    int que(int x,int nl,int nr,int pos){
        if(nl==nr){
            return tr[x];
        }
        int mid=(nl+nr)>>1;
        pushdown(x,nl,nr);
        int res=-INF;
        if(pos<=mid)  res=max(res,que(ls,nl,mid,pos));
        if(pos>mid) res=max(res,que(rs,mid+1,nr,pos));
        return res;

    }
}op;
int a[N],n,q;
int L,R;
int s[N];
typedef unsigned long long ull;
void cal(){
    op.init();
    for(int len=L;len<=R;++len){
        for(int l=1;l+len-1<=n;++l){
            int r=l+len-1;
            op.adt(1,1,n,l,r,s[r]-s[l-1]);
        }
    }
     ull ans=0,INF=0;
    for(int i=1;i<=n;++i){
        long long k=op.que(1,1,n,i);
        ull t=i*((ull)k);
        t+=INF;
        ans^=t;
    }
    cout<<ans<<endl;
}
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    memset(s,0,sizeof s);
    for(int i=1;i<=n;++i)
        cin>>a[i],s[i]=s[i-1]+a[i];
    cin>>q;
    while(q--){
        cin>>L>>R;

        cal();
    }
    return 0;
}
