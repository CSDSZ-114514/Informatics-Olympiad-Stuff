#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[360],b[130];
long long f[45][45][45][45];
int main(){
    cin>>n>>m;
    long long t=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>t,b[t]++;
    f[0][0][0][0]=a[1];
    for(int i=0;i<=b[1];i++){
        for(int j=0;j<=b[2];j++){
            for(int k=0;k<=b[3];k++){
                for(int l=0;l<=b[4];l++){
                    int r=1+i+j*2+k*3+l*4;
                    if(i!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i-1][j][k][l]+a[r]);
                    if(j!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i][j-1][k][l]+a[r]);
                    if(k!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k-1][l]+a[r]);
                    if(l!=0)f[i][j][k][l]=max(f[i][j][k][l],f[i][j][k][l-1]+a[r]);
                }
            }
        }
    }
    cout<<f[b[1]][b[2]][b[3]][b[4]];
    //while(1);
    return 0;
}