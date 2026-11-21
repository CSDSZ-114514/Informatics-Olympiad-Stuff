#include<bits/stdc++.h>
using namespace std;
long long n;
int main(){
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        string s;long long v;cin>>s>>v;
        if(s=="Q"){
            ans+=v;
        }
    }
    cout<<ans;
    return 0;
}