#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005],b[100005];
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m,cmp);
    // for(int i=1;i<=n;i++)cout<<a[i];
    // for(int i=1;i<=m;i++)cout<<b[i];
    long long pur=0,ans=0,rd=1;
    for(int i=1;i<=m;i++){
        if(pur+1<=b[i])pur++;
        else{
            ans+=pur*a[rd];pur=1;
            if(rd+1<=n)rd++;
            else{cout<<-1;return 0;}
        }
    }
    ans+=pur*a[rd];
    cout<<ans;
    return 0;
}