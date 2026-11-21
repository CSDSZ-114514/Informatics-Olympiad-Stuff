#include<bits/stdc++.h>
using namespace std;
long long n,m,k,a[100005],b[100005];
bool check(long long x){
    long long cnt=0;
    for(int i=1;i<=n;i++){
         cnt+=upper_bound(b+1,b+m+1,x-a[i])-b-1; 
    } 
    return cnt>=k;
}
int main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    long long l=0,r=1e15;
    while(l<r){
        long long mid=(l+r)>>1;//cout<<mid<<endl;
        if(check(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<r;
}