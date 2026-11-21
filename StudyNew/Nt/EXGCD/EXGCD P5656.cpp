#include<bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long x1,y1,d;
    d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
int main(){
    long long T;cin>>T;
    for(int i=1;i<=T;i++){
        long long a,b,c;
        cin>>a>>b>>c;
        long long x=0,y=0,d=0;
        d=exgcd(a,b,x,y);
        if(c%d!=0){
            cout<<-1<<endl;continue;
        }else{
            x=x*c/d;y=y*c/d;
            long long dx=b/d,dy=a/d;
            long long k1=ceil(1.0*(-x+1)/dx),k2=floor(1.0*(y-1)/dy);
            if(k1>k2){
                cout<<x+dx*k1<<" "<<y-dy*k2<<endl;continue;
            }else{
                cout<<k2-k1+1<<" ";
                cout<<x+dx*k1<<" "<<y-dy*k2<<" ";
                cout<<x+dx*k2<<" "<<y-dy*k1<<endl;continue;
            }
        }
    }
    return 0;
}