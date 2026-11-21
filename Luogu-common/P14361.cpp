#include<bits/stdc++.h>
using namespace std;
long long t;
struct P{
    long long a,b,c;
    long long maxabc;
}p[1000005];
bool cmp(P x,P y){
    return x.maxabc>y.maxabc;
}
int main (){
    cin>>t;
    while(t--){
        long long ans=0,n=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            long long x=0,y=0,z=0,midxyz=0;
            cin>>x>>y>>z;
            if((x>=y&&y>=z)||(z>=y&&y>=x))midxyz=y;
            else if((x>=z&&z>=y)||(y>=z&&z>=x))midxyz=z;
            else if((y>=x&&x>=z)||(z>=x&&x>=y))midxyz=x;
            x-=midxyz;y-=midxyz;z-=midxyz;
            ans+=midxyz;
            p[i].a=x;p[i].b=y;p[i].c=z;p[i].maxabc=max({x,y,z});
            //cout<<p[i].a<<p[i].b<<p[i].c<<endl;
        }
        //cout<<ans<<endl;
        sort(p+1,p+1+n,cmp);
        // for(int i=1;i<=n;i++){
        //     cout<<p[i].a<<p[i].b<<p[i].c<<endl;
        // }
        long long cnta=0,cntb=0,cntc=0,scnt=0;
        for(int i=1;i<=n;i++){
            if(cnta>=n/2||cntb>=n/2||cntc>=n/2)break;
            if(p[i].maxabc==p[i].a)cnta++;
            if(p[i].maxabc==p[i].b)cntb++;
            if(p[i].maxabc==p[i].c)cntc++;
            ans+=p[i].maxabc;
            scnt=i;
        }
        //cout<<ans<<endl;
        if(scnt==n){
            cout<<ans<<endl;
            continue;
        }else{
            for(int i=scnt;i<=n;i++){
                if(cnta>=n/2){
                    ans+=max({p[i].b,p[i].c});
                }else if(cntb>=n/2){
                    ans+=max({p[i].a,p[i].c});
                }else if(cntc>=n/2){
                    ans+=max({p[i].b,p[i].a});
                }
            }
        }
        cout<<ans<<endl;
    }
}