#include<bits/stdc++.h>
using namespace std;
long long T,n;
long long f9[1000005],f9s[1000005];
int main(){
    freopen("rex.in","r",stdin);
    freopen("rex.out","w",stdout);
    cin>>T;f9[1]=1;f9[2]=1;f9s[1]=1;f9s[2]=2;
    for(int i=3;i<=1e6;i++){
        f9[i]=f9[i-1]+f9[i-2];
        f9[i]%=9;
        f9s[i]=f9s[i-1]+f9[i];
        f9s[i]%=9;
        //cout<<f9s[i]<<" ";
    }
    while(T--){
        cin>>n;
        cout<<f9s[n]<<endl;
    }
}