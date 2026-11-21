#include<bits/stdc++.h>
using namespace std;
const long long mod=19260817;
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

int main(){
    string a,b;cin>>a>>b;
    long long e=0,f=0;
    for(int i=0;i<a.size();i++){
        e*=10;
        e+=(a[i]-'0');
        e%=mod;
    }
    for(int i=0;i<b.size();i++){
        f*=10;
        f+=(b[i]-'0');
        f%=mod;
    }
    long long d=0,x1=0,y1=0;
    d=exgcd(f,mod,x1,y1);
    if(e%d!=0){
        cout<<"Angry!";
    }else{
        x1*=(e/d) ;
        cout<<(x1%(mod/d)+mod/d)%(mod/d);
    }
    return 0;
}