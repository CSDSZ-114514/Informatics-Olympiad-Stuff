#include<bits/stdc++.h>
using namespace std;
long long p[10005], mod = 376544743;
int main(){
    long long n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    long long ans=0;
    for(int i=1;i<(1<<n);i++){
        long long t=1,sign=-1;
        for(int j=1;j<=n;j++){
            if(i>>(j-1)&1){
                t*=p[j];
                if(t>m){
                    break;
                }
                sign*=-1;
            }
        }
        ans=ans+sign*(m/t)*(t+m/t*t)/2;
        ans%=mod;
    }
    cout<<(ans%mod+mod)%mod;
}