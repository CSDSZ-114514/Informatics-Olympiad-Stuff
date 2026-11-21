#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005];
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
long long excrt(long long m[],long long r[]){
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
    return (r1%m1+m1)%m1;

}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    cout<<excrt(a,b);
    return 0;
}