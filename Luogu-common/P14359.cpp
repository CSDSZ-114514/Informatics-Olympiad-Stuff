#include<bits/stdc++.h>
using namespace std;
long long n,k,ans;
long long a[10000005];
long long s[10000005],lst,buc[10000005];
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s[i]=a[i]^s[i-1];
    }
    for(int i=1;i<=n;i++){
        buc[s[i]^k]=-1;
    }
    buc[0]=0;
    for(int i=1;i<=n;i++){
        if(buc[s[i]^k]>=lst){
            lst=i;
            ans++;
        }
        buc[s[i]]=i;
    }
    cout<<ans;
}