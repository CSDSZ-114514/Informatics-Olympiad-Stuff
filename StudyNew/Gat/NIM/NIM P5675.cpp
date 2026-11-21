#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[205];
long long f[205][300];
long long p=1e9+7;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0][0]=1;
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=0;k<=255;k++){
                if(i==j)f[j][k]=f[j-1][k]%p;
                else f[j][k]=(f[j-1][k^a[j]]%p+f[j-1][k]%p)%p;
            }
        }
        for(int j=a[i];j<=255;j++){
            ans=(f[n][j]+ans)%p;
        }
    }
    cout<<ans%p;
}