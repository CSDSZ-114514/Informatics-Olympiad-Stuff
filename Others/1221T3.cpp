#include<bits/stdc++.h>
using namespace std;
long long n,q,x;
long long a[1000005][4];
int main(){
    cin>>n>>q>>x;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]; 
        if(a[i][1]<a[i][2])swap(a[i][1],a[i][2]);
    }
    long long dp0=abs(x-a[1][1]);
    long long dp1=abs(x-a[1][2]);
    dp0=min(dp1,dp0);dp1=dp0;
    for(int i=2;i<=n;i++){
        long long temp1=min(dp0+abs(a[i-1][1]-a[i][1]),dp1+abs(a[i-1][2]-a[i][1]));
        long long temp2=min(dp0+abs(a[i-1][1]-a[i][2]),dp1+abs(a[i-1][2]-a[i][2]));
        dp0=min(temp1,temp2);dp1=dp0;
    }
    for(int i=1;i<=q;i++){
        long long x1;cin>>x1;
        cout<<min(dp0+abs(a[n][1]-x1),dp1+abs(a[n][2]-x1))+(n-1)<<"\n";
    }
    return 0;
}