#include<bits/stdc++.h>
using namespace std;
long long phi[1000005];
void get_phi(long long n){
    for(int i=1;i<=n;i++)phi[i]=i;
    for(int i=2;i<=n;i++){
        if(phi[i]==i){
            phi[i]=i-1;
            for(int j=2;i*j<=n;j++){
                phi[i*j]=phi[i*j]/i*(i-1);
            }
        }
    }
}
int main(){
    long long n;cin>>n;
    if(n==1){cout<<0;return 0;}
    long long ans=3;
    get_phi(1000005);
    for(int i=2;i<=n-1;i++){
        ans+=2*phi[i];
    }
    cout<<ans;
}