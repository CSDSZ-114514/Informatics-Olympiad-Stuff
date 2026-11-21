#include<bits/stdc++.h>
#include<set>
using namespace std;
long long T,n;
long long a[1000005],p[1000005],k[1000005];
__int128 m[1000005],r[1000005],maxx=-1e9;
multiset<long long> s;
__int128 exgcd(__int128 a,__int128 b,__int128 &x,__int128 &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    __int128 x1,y1;
    __int128 d=exgcd(b,a%b,x1,y1);
    x=y1;y=x1-a/b*y1;
    return d;
}
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long x1=0,y1=0,d=0;
    d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
long long excrt(__int128 m[],__int128 r[]){
    __int128 m1,m2,r1,r2;
    m1=m[1];r1=r[1];
    for(int i=2;i<=n;i++){
        m2=m[i],r2=r[i];
        __int128 p,q,d;
        d=exgcd(m1,m2,p,q);
        if((r2-r1)%d!=0){
            return -1;
        }
        p=p*(r2-r1)/d;
        p=(p%(m2/d)+(m2/d))%(m2/d);
        
        r1=m1*p+r1;
        m1=m1*m2/d;
    }
    __int128 res = (r1%m1+m1)%m1;
    if(res<maxx){
        long long k=ceil(1.0*(maxx-res)/m1);
        res+=k*m1;
    }
    return res;

}
int main(){
    cin>>T;
    while(T--){
        long long m4;
        cin>>n>>m4;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>p[i];
        for(int i=1;i<=n;i++)cin>>k[i];
        for(int i=1;i<=m4;i++){
            long long t;cin>>t;
            s.insert(t);
        }
        for(int i=1;i<=n;i++){
            auto it=s.upper_bound(a[i]);
            if(it!=s.begin()){
                --it;
            }
            __int128 b=*it;
            s.erase(it);
            s.insert(k[i]);
            maxx=max(1.0*maxx,ceil(1.0*a[i]/b));
            __int128 x1=0,y1=0;
            __int128 d1=exgcd(b,p[i],x1,y1);
            if(a[i]%d1!=0){
                cout<<-1<<endl;
                goto end;
            }
            x1=x1*(a[i]/d1); 
            x1=(x1%(p[i]/d1)+(p[i]/d1))%(p[i]/d1);
            m[i]=p[i]/d1;
            r[i]=x1;
        }
        cout<<excrt(m,r)<<endl;
        end:
        s.clear();
        maxx=0;
    }
    return 0;
}