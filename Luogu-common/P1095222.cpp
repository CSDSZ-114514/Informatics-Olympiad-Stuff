#include<bits/stdc++.h>
using namespace std;
long long m,s,t,dp[10005][1005];
int main(){
    freopen("P1095.out","w",stdout);

    cin>>m>>s>>t;
    memset(dp,-1,sizeof(dp));
    dp[0][m]=0;
    for(int i=1;i<=t;i++){
        for(int j=0;j<=m+10;j++){
            if(dp[i-1][j]!=-1){
                dp[i][j]=max(dp[i][j],dp[i-1][j]+17);
            }
            if(j+10<=m+10){
                if(dp[i-1][j+10]!=-1){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+10]+60);
                }
            }
            if(j-4>=0){
                if(dp[i-1][j-4]!=-1){
                    dp[i][j]=max(dp[i][j],dp[i-1][j-4]);
                }
            }
            
            //if(i!=1&&dp[i-1][j+10]==0)continue;
        }
    }
    for(long long i=0;i<=m+10;i++){
        for(long long j=0;j<=t;j++){
            cout<<left<<setw(5)<<dp[j][i]<<" ";
        }
        cout<<endl;
    }
    long long mxs=0,mit=INT_MAX;bool flag=false;
    for(long long i=1;i<=t;i++){
        for(long long j=0;j<=m+10;j++){
            if(dp[i][j]>=s){
                flag=true;
                mit=min(mit,i);
            }
            mxs=max(mxs,dp[i][j]);
        }
    }
    if(flag){
        cout<<"Yes"<<endl;
        cout<<mit;
    }else{
        cout<<"No"<<endl;
        cout<<mxs;
    }
    system("pause");
    return 0;
}
