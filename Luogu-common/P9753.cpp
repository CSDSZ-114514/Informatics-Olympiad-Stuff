#include<bits/stdc++.h>
using namespace std;
long long n;string str;
long long f[5000005],g[5000005],ans;
int main(){
    cin>>n;cin>>str;
    str=" "+str;
    for(int i=1;i<=n;i++){
        long long j=i-1;
        while(j>0){
            if(str[i]==str[j]){
                g[i]=j;break;
            }
            j=g[j]-1;
        }
        if(g[i])f[i]=f[g[i]-1]+1;ans+=f[i];
    }
    cout<<ans;
    return 0;
}