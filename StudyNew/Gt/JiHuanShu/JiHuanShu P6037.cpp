#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+5;
int n,root,pre[N],ans[N];
long long sum;
struct ED{
    int u,v,w,p;
};
bool vis[N];
vector<ED> e;
vector<int> h[N];
vector<int> ring;

void find(long long u,long long fa){
    vis[u]=true;
    for(long long i:h[u]){
        long long v=e[i].v;
        if(v!=fa){
            if(vis[v]==0){
                pre[v]=i;
                find(v,u);
            }else{
                if(root==0){
                    root=v;
                    pre[root]=i;
                }
                return;
            }
        }
    }
}
void dfs(long long u,long long fa){
    for(long long i:h[u]){
        long long v=e[i].v;
        if(v!=fa&&vis[v]==0){
            ans[v]=ans[u];
            dfs(v,u);
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long u,v,w,p;cin>>u>>v>>w>>p;
        sum+=w;
        e.push_back({u,v,w,p});
        h[u].push_back(e.size()-1);
        e.push_back({v,u,w,p});
        h[v].push_back(e.size()-1);
    }
    find(1,1);
    //cout<<"root:"<<root<<endl;
    long long L=pre[root];
    long long u=e[L].u;
    //cout<<"u:"<<u<<endl;
    long long R=pre[u];
    memset(vis,0,sizeof(vis));
    
    while(1){
        vis[u]=1;
        R=pre[u];
        ring.push_back(u);
        if(e[L].p>e[R].p){
            ans[u]=e[R].w;
        }else{
            ans[u]=e[L].w;
        }
        if(u==root)break;
        L=R;
        u=e[R].u;
        //cout<<"u:"<<u<<":"<<ans[u]<<endl;
    }
    
    for(int i:ring){
        dfs(i,i);
    }
    //cout<<11111111111;
    for(int i=1;i<=n;i++){
        cout<<sum-ans[i]<<endl;
    }
    return 0;
}