#include<bits/stdc++.h>
using namespace std;
struct ZD{
    long long dis,mxc;
}zd[1000005];
struct CARa{
    long long toa,tob;
}cara[1000005];
struct CARb{
    long long toa,tob;
}carb[1000005];
bool cmpa(CARa x,CARa y){
    return (x.toa-x.tob)>(y.toa-y.tob);
}
bool cmpb(CARb x,CARb y){
    return (x.toa-x.tob)<(y.toa-y.tob);
}
bool cmp1(ZD x,ZD y){
    return x.dis<y.dis;
}

long long n,m,c,cnta,cntb;

int main(){
    cin>>n>>m>>c;
    for(int i=1;i<=n;i++){
        cin>>zd[i].dis>>zd[i].mxc;
    }
    for(int i=1;i<=m;i++){
        long long a,b;cin>>a>>b;
        //cout<<1;
        if(a>=b){
            cara[++cnta].toa=a,cara[cnta].tob=b;
        }else{
            carb[++cntb].toa=a;carb[cntb].tob=b;
        }
    }
    sort(cara+1,cara+1+cnta,cmpa);
    sort(carb+1,carb+1+cntb,cmpb);
    sort(zd+1,zd+1+n,cmp1);
    // cout<<endl;
    // for(int i=1;i<=cnta;i++)cout<<cara[i].toa-cara[i].tob<<" ";
    // cout<<endl;
    // for(int i=1;i<=cntb;i++)cout<<carb[i].toa-carb[i].tob<<" ";
    // cout<<endl;
    // for(int i=1;i<=n;i++)cout<<zd[i].dis<<":"<<zd[i].mxc<<" ";
    // cout<<endl;
    long long ans=0;long long used=1;
    for(int i=1;i<=cnta;i++){
        if(zd[used].mxc==0)used++;
        zd[used].mxc--;
        //cout<<cara[i].toa<<":"<<cara[i].tob<<":"<<zd[used].dis<<endl;
        ans=ans+2*cara[i].toa*zd[used].dis+2*cara[i].tob*(c-zd[used].dis);		
    }
    used=n;
    for(int j=1;j<=cntb;j++){
        if(zd[used].mxc==0)used--;
        zd[used].mxc--;
        ans=ans+2*carb[j].toa*zd[used].dis+2*carb[j].tob*(c-zd[used].dis);	
    }
    cout<<ans;
}