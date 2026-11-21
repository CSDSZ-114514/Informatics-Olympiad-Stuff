#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long x[100005],y[100005],dp[100005];
int main(){
    int T;cin>>T;
    while(T--){
        cin>>n>>t;
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n;i++)cin>>y[i];
        for(int i=0;i<=n+1;i++)dp[i]=n+1;
        dp[1]=1;
        for(int i=1;i<=n-1;i++){
            long long a,b,c,d;
            bool flag=true;
            for(int j=i+1;j<=n;j++){
                if(j>i+1){
                    int k=j-1;
                    long long aa=y[k]-t-y[i];
                    long long bb=x[k]-x[j];
                    long long cc=y[k]+t-y[j];
                    long long dd=x[k]-x[j];
                    if(flag){
                        a=aa;b=bb;c=cc;d=dd;
                            flag=false;
                    }else{
                        if(aa*b>bb*a){
                            a=aa;b=bb;
                        }
                        if(cc*d<c*dd){
                            c=cc;
                            d=dd;
                        }
                    }
                }
                if(j==i+1){
                    if(dp[i]+1<dp[j])dp[j]=dp[i]+1;
                }else{
                    long long dy=y[j]-y[i];
                    long long dx=x[j]-x[i];
                    if(dy*b>=a*dx&&dy*d>=c*dx){
                        if(dp[i]+1<dp[j])dp[j]=dp[i]+1;
                    }
                }
            }
        }
        cout<<n-dp[n]<<endl;
    }
    return 0;
}