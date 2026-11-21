#include<bits/stdc++.h>
using namespace std;
long long n=3;
long long M=1;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long d,x1,y1;
    d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
long long crt(long long m[],long long r[]){
    M=1;
    for(int i=1;i<=n;i++)M*=m[i];
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long c=M/m[i];
        long long x,y;
        exgcd(c,m[i],x,y);
        ans=(ans+(__int128)r[i]*c*x)%M;
    }
    return (ans+M)%M;
}
int main(){   
    long long z=1;
    while(true){
        long long p,e,d,i;
        cin>>p>>e>>i>>d;
        if(p==-1){
            break;
        }
        long long a[5]={0,p%23,e%28,i%33},b[5]={0,23,28,33};
        long long x=crt(b,a);
        if(x>d)x=x-d;
        else x=x+M-d;
        cout<<"Case "<<z<<": the next triple peak occurs in "<<x<<" days."<<endl;
        z++;
    }
    return 0;
}