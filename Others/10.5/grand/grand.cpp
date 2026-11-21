#include<bits/stdc++.h>
using namespace std;
long long n,ans;
bool used[1000005];
struct AA{
    long long ti,ri;
}a[1000005];
bool cmp(AA x,AA y){
    return x.ri>y.ri;
}
int main(){
    freopen("grand.in","r",stdin);
    freopen("grand.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i].ti;
    for(int i=1;i<=n;i++)cin>>a[i].ri;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        bool isfree=false;
        for(int j=a[i].ti;j>=1;j--){
            if(!used[j]){
                used[j]=j;
                isfree=true;
                break;
            }
        }
        if(isfree){
            ans+=a[i].ri;
        }
    }
    //for(int i=1;i<=n;i++)cout<<used[i]<<" ";
    cout<<ans;
}