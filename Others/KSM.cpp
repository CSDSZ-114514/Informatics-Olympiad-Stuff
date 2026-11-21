#include<bits/stdc++.h>
using namespace std;
long long ksm(long long a,long long b,long long p){
    long long ans=1;
    while(b>0){
        if(b%2==1){
            ans*=a;ans%=p;
        }
        a=a*a%p;
        b/=2;
    }
    return ans;
}
int main(){
    long long a,b,p;
    cin>>a>>b>>p;
    cout<<a<<"^"<<b<<" mod "<<p<<"="<<ksm(a,b,p);
    return 0;
}