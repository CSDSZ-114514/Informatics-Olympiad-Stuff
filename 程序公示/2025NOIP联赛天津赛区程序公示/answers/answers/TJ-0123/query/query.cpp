#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
ull n,a[500009],q,s[500009];
int main(){
    freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n;
    for (int i=1;i<=n;i++)cin>>a[i];
    for (int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    cin>>q;
    for (int i=1;i<=q;i++){
        int x,y;
        cin>>x>>y;
        ull ans=0;
        for (int z=1;z<=n;z++){
            ull res=-1e18;
            for (int j=x;j<=y;j++){
                for (int k=max<int>(1,z-j+1)+j-1;k<=min<int>(n,z+j-1);k++){
                    res=max(res,s[k]-s[k-j]);
                }
            }
            res*=z;
            ans^=res;
        }
        cout<<ans<<"\n";
    }
}
