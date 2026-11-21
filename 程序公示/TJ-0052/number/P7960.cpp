#include<bits/stdc++.h>
using namespace std;
long long T;bool flg[100000015];
long long cng[10000015],cngq[10000015];
bool check7(long long a){
    while(a>0){
        if(a%10==7)return true;
        a/=10;
    }
    return false;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>T;
    long long cnt=0;
    for(long long i=1;i<=1e7+10;i++){
        if(flg[i])continue;
        if(check7(i)){
            for(int j=1;j*i<=1e7+10;j++){
                flg[i*j]=1;
            }
        }else{
            cng[++cnt]=i;
            cngq[i]=cnt;
        }
    }
    // for(int i=1;i<=50;i++){
    //     cout<<cng[i]<<" ";
    // }
    for(int i=1;i<=T;i++){
        long long x;cin>>x;
        if(!flg[x])cout<<cng[cngq[x]+1]<<endl;
        else cout<<-1<<endl;
    }
}