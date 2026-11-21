#include<bits/stdc++.h>
using namespace std;
long long n,r;
long long c[1005][1005],ans;
int main(){
    cin>>n>>r;
    for(int i=0;i<=r;i++){
        c[i][0]=1;
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=i;j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    for(int i=0;i<=r;i++){
        if(i&1){
            ans-=c[r][i]*pow(r-i,n);
        }else{
            ans+=c[r][i]*pow(r-i,n);
        }
    }
    cout<<ans;

    return 0;
}