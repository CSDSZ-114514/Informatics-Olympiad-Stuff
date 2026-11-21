#include<bits/stdc++.h>
using namespace std;
long long n,a,b,w[1000005],f[1005][1005];
int main(){
    freopen("transport.in","r",stdin);
    freopen("transport.out","w",stdout);
    cin>>n>>a>>b;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    long long mxn=-1e9;
    for(int i=1;i<=n;i++){
        for(int j=a;j>=0;j--){
            for(int k=b;k>=0;k--){
                if(j-w[i]>=0){
                    f[j][k]=max(f[j][k],f[j-w[i]][k]+w[i]);
                }
                if(k-w[i]>=0){
                    f[j][k]=max(f[j][k],f[j][k-w[i]]+w[i]);
                }
                mxn=max(f[j][k],mxn);
            }
        }
    }
    // for(int i=1;i<=a;i++){
    //     for(int j=1;j<=b;j++){
    //         cout<<f[i][j]<<" ";

    //     }
    //     cout<<endl;
    // }
    cout<<mxn;
    return 0;
}