#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a1[1005],b1[1005],a2[1005],b2[1005],f[1005][1005];
int main(){
    long long T;cin>>T;
    for(int s=1;s<=T;s++){
        memset(a1,0,sizeof(a1));
        memset(a2,0,sizeof(a2));
        memset(b1,0,sizeof(b1));
        memset(b2,0,sizeof(b2));
        memset(f,0,sizeof(f));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a1[i]>>a2[i];
        }
        for(int i=1;i<=m;i++){
            cin>>b1[i]>>b2[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j]=max(f[i-1][j],f[i][j-1]);
                if(a2[i]!=b2[j])continue;
                long long ci=0;
                for(int k=i;k>=1;k--){
                    if(a2[i]==a2[k]){
                        ci+=a1[k];
                        long long cj=0;
                        for(int r=j;r>=1;r--){
                            if(b2[j]==b2[r]){
                                cj+=b1[r];
                                f[i][j]=max(f[i][j],f[k-1][r-1]+min(ci,cj));
                            }
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<s<<": "<<f[n][m]<<endl;
    }
    return 0;
}