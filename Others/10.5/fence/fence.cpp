#include<bits/stdc++.h>
using namespace std;
long long n,L,a[1000005];
long long s[100005];
bool check(long long x){
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i]-x;
    }
    long long minx=1e9;
    for(int i=L;i<=n;i++){
        minx=min(minx,s[i-L]);
        if(s[i]-minx>=0)return 1; 
    }
    return 0;
}
int main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    cin>>n>>L;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]*=1000;
    }
    long long l=1,r=2000000;
    while(l<r){
        long long mid=(l+r)>>1;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l;
}