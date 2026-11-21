#include<bits/stdc++.h>
using namespace std;
namespace Main{
const int N=8e3+10;
struct edge{int to,next;}dat[N<<1];
int T,n,m,fa[N],h[N],it;
void init(){it=0;
    for(int i=1;i<=n;i++){h[i]=-1;}
}
void addedge(int u,int v){
    dat[it]={v,h[u]};h[u]=it++;
}
namespace Brute{
const int N=10;
int val[N];bool mem[N][N];
int dfs(int id){
    int ans=0;
    for(int i=h[id];i!=-1;i=dat[i].next){
        int v=dat[i].to;
        ans+=dfs(v);
        for(int i=0;i<=n;i++){
            if(mem[v][i])mem[id][i]=1;
        }
    }mem[id][val[id]]=1;
    for(int i=0;i<=n;i++){
        if(!mem[id][i])return ans+i;
    }
    assert(false);
    return -1;
}
int get(int id){int ans=0;

    if(id==n+1){
        memset(mem,0,sizeof mem);
        return dfs(1);
    }
    for(int i=1;i<=n;i++){
        val[id]=i;
        ans=max(get(id+1),ans);
    }
    return ans;
}
int main(){
    return get(1);
}
}
void main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);init();
        for(int i=2;i<=n;i++){
            scanf("%d",&fa[i]);
            addedge(fa[i],i);
        }//cerr<<"proc";
        Brute::main();
    }
}
}
signed main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    Main::main();
    return 0;
}
