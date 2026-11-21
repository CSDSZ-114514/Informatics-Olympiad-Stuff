#include<bits/stdc++.h>
using namespace std;
long long n,k,T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>T;
    while(T--){
        cin>>n>>k;
        long long ans=INT_MAX;
        for(int i=sqrt(n);i>=1;i--){
            if(i+n/i>=ans)break;
            ans=min(ans,i+n/i+k*(n%i));
        }
        ans=min(ans,k*n);
        cout<<ans<<'\n';
    }
}