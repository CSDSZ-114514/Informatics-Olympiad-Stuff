#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long l[400005],r[400005],cf[400005],qzh[400005];
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>l[i]>>r[i];
        cf[l[i]]++;cf[r[i]+1]--;
    }
    long long ans=0,ansn=0;
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+cf[i];
        //cout<<qzh[i]<<" ";
        if(qzh[i]==0){
            ansn++;
        }
    }
    for(int i=1;i<=m;i++){
        ans=0;
        for(int j=l[i];j<=r[i];j++){
            if(qzh[j]==1){
                ans++;
            }
        }
        cout<<ans+ansn<<endl;
    }

    return 0;
}