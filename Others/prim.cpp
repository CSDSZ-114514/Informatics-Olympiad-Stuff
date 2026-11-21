#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct EDGE{
    long long to,val;
};
vector<EDGE> e[100005];
long long d[100005];
bool vis[100005];
long long prim(long long s){
    for(int i=0;i<=n;i++){
        d[i]=1e9;
    }
    d[s]=0;
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long u=0;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&d[j]<d[u]){
                u=j;
            }
        }
        vis[u]=1;
        sum+=d[u];
        for(EDGE t:e[u]){
            if(!vis[t.to]&&d[t.to]>t.val){
                d[t.to]=t.val;
            }
        }
        for(int j=1;j<=n;j++){
            cout<<d[j]<<" ";
        }
        cout<<endl;
    }
    return sum;

}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long x,y,z;cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    cout<<prim(1);

}