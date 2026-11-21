#include<bits/stdc++.h>
using namespace std;
long long n;
const long long N=1e5+5;
double k,ans;
long long idx=-1;
double p[N],f[N][3];
struct ED{
    long long u,v;
};
vector<ED> e;
vector<long long>h[N];
bool vis[N];
void find(long long u,long long fa){
    vis[u]=true;
    for(long long i:h[u]){
        long long v=e[i].v;
        if(v!=fa){
            if(vis[v]==0){
                find(v,u);
            }else{
                idx=i;
            }
        }
    }
}
void dfs(long long u,long long fa){
    f[u][0] = 0;
	f[u][1] = p[u]*k;
    for(long long i:h[u]){
        long long v=e[i].v;
        if(v!=fa&&!(i==idx||i==(idx^1))){
            dfs(v,u);
            f[u][0]+=max(f[v][1],f[v][0]);
		    f[u][1]+=f[v][0];
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        long long u,v;cin>>u>>v;
        u++;v++;
        e.push_back({u,v});
        h[u].push_back(e.size()-1);
        e.push_back({v,u});
        h[v].push_back(e.size()-1);
    }
    cin>>k;
    find(1,1);
    dfs(e[idx].u,e[idx].u);
    ans=f[e[idx].u][0];
    dfs(e[idx].v,e[idx].v);
    ans=max(ans,f[e[idx].v][0]);
    cout<<fixed<<setprecision(1)<<ans;
    return 0;
}