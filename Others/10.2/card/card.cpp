#include<bits/stdc++.h>
using namespace std;
long long n,cf[100005],a[100005],sum1,sum2;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cf[i]=a[i]-a[i-1];
        if(cf[i]<0){
            sum1-=cf[i];
        }else if(cf[i]>0){
            sum2+=cf[i];
        }
    }
    cout<<max(sum1,sum2);
    return 0;
}