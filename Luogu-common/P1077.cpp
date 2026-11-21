#include<bits/stdc++.h>
using namespace std;
long long a[10000],f[1005][1005];
long long m,n;
const long long mod=1e6+7;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    f[0][0] = 1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<=m;j++){
            for(int k=0;k<=a[i];k++){
                if(j-k>=0){
                    f[i][j]+=f[i-1][j-k]%mod;
                }
            }
        }
    }
    cout<<f[n][m]%mod;
    return 0;
}