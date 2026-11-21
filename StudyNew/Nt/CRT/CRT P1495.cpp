#include<bits/stdc++.h>
using namespace std;
long long n,a[100005],b[100005];
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long x1,y1;
    long long d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
long long crt(long long m[],long long r[]){
    long long M=1;long long ans=0;
    for(int i=1;i<=n;i++){
        M*=m[i];
    }
    for(int i=1;i<=n;i++){
        long long c=M/m[i];
        long long x,y;
        exgcd(c,m[i],x,y);
        ans=(ans+(__int128)r[i]*c*x)%M;
    }
    return (ans+M)%M;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
    cout<<crt(a,b);
}