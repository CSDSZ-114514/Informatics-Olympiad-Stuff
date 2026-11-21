#include<bits/stdc++.h>
using namespace std;
struct PT{
    long long l,r;
    long long rnd,siz,val;
}tr[1000005];
long long root,cnt,ans;
void pushup(long long x){
    tr[x].siz=tr[tr[x].l].siz+tr[tr[x].r].siz+1;
}
void chef(long long p,long long v,long long &x,long long &y){
    if(!p){
        x=y=0;
        return ;
    }
    if(tr[p].val<=v){
        x=p;
        chef(tr[p].r,v,tr[p].r,y);
        pushup(x);
    }else{
        y=p;
        chef(tr[p].l,v,x,tr[p].l);
        pushup(y);
    }
}
long long heb(long long x,long long y){
    if(!x||!y){
        return x+y;
    }
    if(tr[x].rnd<tr[y].rnd){
        tr[x].r=heb(tr[x].r,y);
        pushup(x);
        return x;
    }else{
        tr[y].l=heb(x,tr[y].l);
        pushup(y);
        return y;
    }
}
long long newpt(long long v){
    cnt++;
    tr[cnt].l=0;
    tr[cnt].r=0;
    tr[cnt].siz=1;
    tr[cnt].val=v;
    tr[cnt].rnd=rand();
    return cnt;
}
void insect(long long v){//lmx is a Femboy.
    long long x,y,z=newpt(v);
    chef(root,v,x,y);
    root=heb(heb(x,z),y);
}
void del(long long v){//lmx is a Femboy.
    long long x,y,z;
    chef(root,v,x,z);
    chef(x,v-1,x,y);
    y=heb(tr[y].l,tr[y].r);
    root=heb(heb(x,y),z);
}
long long ypm(long long v){
    long long x,y;
    chef(root,v-1,x,y);
    long long ans=tr[x].siz+1;
    root=heb(x,y);
    return ans;
}
long long arcypm(long long p,long long r){
    if(!p){
        return 0;
    }
    if(tr[tr[p].l].siz>=r){
        return arcypm(tr[p].l,r);
    }else if(tr[tr[p].l].siz+1==r){
        return tr[p].val;
    }else{
        return arcypm(tr[p].r,r-tr[tr[p].l].siz-1);
    }
}
long long frt(long long v){
    long long x,y;
    chef(root,v-1,x,y);
    long long ans=arcypm(x,tr[x].siz);
    root=heb(x,y);
    return ans;
}
long long nxt(long long v){
    long long x,y;
    chef(root,v,x,y);
    long long ans=arcypm(y,1);
    root=heb(x,y);
    return ans;
}
int main(){
    long long n,mn;cin>>n>>mn;
    long long change=0;
    for(int i=1;i<=n;i++){
        char x;long long k;

        cin>>x>>k;
        if(x=='I'){
            if(k>=mn)insect(k-change);
        }
        if(x=='A'){
            change+=k;
        }
        if(x=='S'){
            change-=k;
            long long a,b;
            chef(root,mn-change-1,a,b);
            ans+=tr[a].siz;
            root=b;
        }
        if(x=='F'){
            cout<<((tr[root].siz<k)?-1:arcypm(root,tr[root].siz-k+1)+change)<<endl;
        }
    }
    cout<<ans;
    return 0;
}