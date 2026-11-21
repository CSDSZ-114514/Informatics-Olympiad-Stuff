#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
    long long n,t;cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);bool flg=true;
        for(int i=1;i<=n-2;i++)if(a[i]!=__gcd(a[n],a[n-1])){cout<<"No"<<endl;flg=false;break;}
        if(flg)cout<<"Yes"<<endl;
    }
}