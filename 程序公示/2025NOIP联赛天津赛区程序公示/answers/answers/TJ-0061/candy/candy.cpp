#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N=10010;
int n;
long long m,ans;
pair<int,int> v[N];
long long dv=9223372036854775807;
int ov[N];
int main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v[i].x,&v[i].y);
        dv=min(dv,(long long)v[i].x+(long long)v[i].y);
        ov[i]=v[i].x;
    }
    sort(ov+1,ov+n+1);
    int i=1;
    while(dv-(long long)ov[i]>(long long)ov[i]&&i<=n){
        if(m-(long long)ov[i]>=0)
            m-=(long long)ov[i],ans++;
        else{
            cout<<ans<<'\n';
            return 0;
        }i++;
    }if(m==0){
        cout<<ans<<'\n';
        return 0;
    }
    ans+=m/dv*2;
    if(i<=n&&m%dv>=(long long)ov[i])
        ans++;
    cout<<ans<<'\n';
    return 0;
}//I NEED POINTS.!
 //100 just ok.
 //100 best.( ._.)