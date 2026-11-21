#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
long long c[2005][2005],ans;
long long  mo=1e9+7;
int main(){
    cin>>n>>m;
    for(int i=0;i<=2000;i++){
        c[i][0]=1;
    }
    for(int i=1;i<=2000;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
            c[i][j]%=(mo);
        }
    }
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    
    
    for(int i=0;i<=n;i++){
        long long t=1;
        for(int j=1;j<=m;j++){
            t*=c[a[j]+n-i-1][n-i-1];
            t%=mo;
        }
        if(i&1){
            ans-=c[n][i]*t;
        }else{
            ans+=c[n][i]*t;
        }
        ans%=(mo);
    }
    cout<<(ans%(mo)+(mo))%(mo);
    return 0;
    
}