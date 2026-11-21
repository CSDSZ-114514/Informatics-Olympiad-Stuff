#include<bits/stdc++.h>
using namespace std;
long long n;
long long getphi(long long n){
    long long res=n;
    for(long long i=2;i<=sqrt(n);i++){
        if(n%i==0){
            res=res/i*(i-1);
        }
        while(n%i==0){
            n/=i;
        }
    }
    if(n>1){
        res=res/n*(n-1);
    }
    return res;
}
int main(){
    cin>>n;
    long long ans=0;
    for(int i=1;i<=sqrt(n);i++){
        if(n%i==0){
            ans+=i*getphi(n/i);
            if(n==i*i)continue;
            ans+=(n/i)*getphi(n/(n/i));
        }
    }
    cout<<ans;
    return 0;
}