#include<bits/stdc++.h>
using namespace std;
long long m,n,ans;
struct tsk{
    long long ti,co;
}TK[10005];
bool vis[100005],vis2[100005];
bool cmp(tsk x,tsk y){
    return x.co>y.co;
}
int main(){
    freopen("surf.in","r",stdin);
    freopen("surf.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++)cin>>TK[i].ti;
    for(int i=1;i<=n;i++)cin>>TK[i].co;
    sort(TK+1,TK+1+n,cmp);

    for(long long i=1;i<=n;i++){
        for(int j=TK[i].ti;j>=1;j--){
            if(!vis[j]){
                vis[j]=1;
                vis2[i]=1;
                break;
            }
        }
        if(!vis2[i]){
            ans+=TK[i].co;
        }
    }
    cout<<max(m-ans,(long long)0);
    return 0;
}