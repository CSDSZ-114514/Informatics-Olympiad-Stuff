#include<bits/stdc++.h>
using namespace std;
namespace Main{
using lnt =long long;using Pair=pair<int,int>;
const int N=1e5+10;
int n;lnt m,ans;Pair dat[N],choose;
lnt sum(const Pair &a){return 0ll+a.first+a.second;}
lnt getans(lnt rem){
    //cerr<<' '<<rem<<' '<<sum(choose)<<'\n';
    return ((rem/sum(choose))<<1)+((rem%sum(choose))>=choose.second);
}
void main(){
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        int x,y;scanf("%d%d",&x,&y);
        dat[i]={x,y};
    }
    sort(dat+1,dat+n+1);lnt used=0;
    for(int i=1;i<=n;i++){
        used+=dat[i].first;
        if(used<=m)ans=i;
    }
    sort(dat+1,dat+n+1,[](const Pair &a,const Pair &b){return sum(a)<sum(b) || (sum(a)==sum(b) && a.first<b.first);});
    choose=dat[1];
    //cerr<<choose.first<<' '<<choose.second<<'\n';
    sort(dat+2,dat+n+1);used=0;
    for(int i=1;i<=n;i++){
        used+=dat[i].first;
        if(used>m)break;
        ans=max(i+getans(m-used),ans);
        //cerr<<i+getans(m-used)<<' ';
    }
    printf("%lld\n",ans);
}
}
signed main(){
    freopen("candy.in","r",stdin);
    freopen("candy.out","w",stdout);
    Main::main();
    return 0;
}
