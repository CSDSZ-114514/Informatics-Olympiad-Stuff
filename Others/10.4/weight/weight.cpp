#include<bits/stdc++.h>
using namespace std;
long long n,q,a[1000005];
int main(){
    freopen("weight.in","r",stdin);
    freopen("weight.out","w",stdout);
    cin>>n>>q;
    for(int i=0;i<n;i++)for(int j=1;j<=n;j++)cin>>a[i*n+j];
    sort(a+1,a+1+n*n);
    //for(int i=1;i<=n*n;i++)cout<<a[i]<<" ";
    for(int i=1;i<=q;i++){
        long long b;cin>>b;
        //long long l=1,r=n*n;

        //long long ans=n*n-r;
        //cout<<n*n-(lower_bound(a+1,a+1+n*n,b)-a)+1<<endl;
        //cout<<n*n-r<<" ";
        //cout<<min(,n)<<endl;
        cout<<min(n*n-(lower_bound(a+1,a+1+n*n,b)-a)+1,n)<<endl;
    }

    return 0;
}