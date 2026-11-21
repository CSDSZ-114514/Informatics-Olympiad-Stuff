#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long nn[100005],nm[100005],ans;
int main(){
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=k;j+=i){
            nn[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=k;j+=i){
            nm[j]++;
        }
    }
    for(int i=1;i<=k;i++){
        ans=ans+(long long)i*nn[i]*nm[i];
    }
    cout<<ans;
}