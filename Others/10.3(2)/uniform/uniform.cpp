#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
long long n,m,a[N],b[N],ans,mxa=-1e9;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],mxa=max(mxa,a[i]);
    for(int i=1;i<=m;i++)cin>>b[i];
    for(int i=1;i<=m;i++){
        for(int j=b[i];j<=n;j+=b[i]){
            if(j*a[j]==i*b[i])ans++;
        }
    }
    cout<<ans;
}