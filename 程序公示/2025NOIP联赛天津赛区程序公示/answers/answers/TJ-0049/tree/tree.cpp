#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=1005;
struct Edge{
    int to,next;
}e[N];
int head[N],idx=0;
void addedge(int u,int v){
    e[idx].to=v;
    e[idx].next=head[u];
    head[u]=idx++;
}
int n,m;
int siz[N];
int dfsl[N],dfsr[N],dfn=0;
int top[N];
void gets(int x){
    siz[x]=1;
    dfsl[x]=++dfn;
    top[dfn]=x;
    //cout<<"x: "<<x<<" "<<dfn<<'\n';
    for(int i=head[x];~i;i=e[i].next){
        int v=e[i].to;
        gets(v);
        siz[x]+=siz[v];
    }
    dfsr[x]=dfn;
}

/*
namespace DP{
    int f[N][N];

    void dfs(int x){
        f[x][0]=0;
        int tmp[N];
        memset(tmp,-127,sizeof tmp);
        int maxk[N];
        for(int i=head[x];~i;i=e[i].next){
            int v=e[i].to;
            dfs(v);
            for(int j=0;j<siz[v];++j){
                if(f[v][j]>=0){
                    tmp[j+1]=max(0,tmp[j+1]);
                    tmp[j+1]=max(tmp[j+1],f[v][j]+j+2+tmp[j+1]);
                    for(int nv=j+2;nv<=siz[x];++nv){
                        tmp[j+2]=max(0,tmp[j+2]);
                        tmp[j+2]=max(tmp[j+2],f[v][j]+tmp[j+2]+j+1);
                    }
                }
            }
        }
        for(int j=0;j<siz[x];++j)
            f[x][j]=max(tmp[j],f[x][j]);


    }
    void main(){
        memset(f,-127,sizeof f);

    }
}
*/

namespace BL{
    int val[N];
    bool hasin[N][N];
    int ans=0;
    int nans=0;
    void dpcal(int x){
       for(int i=head[x];~i;i=e[i].next){
        int v=e[i].to;
        dpcal(v);
        for(int j=0;j<siz[1];++j)
            hasin[x][j]|=hasin[v][j];
       }
       hasin[x][val[x]]=1;
       for(int j=0;j<siz[1];++j)
       if(!hasin[x][j]){
        nans+=j;
        break;
       }
    }
    void cal(){
        memset(hasin,0,sizeof hasin);
        nans=0;
        dpcal(1);
        ans=max(nans,ans);
    }
    void dfs(int now){//now shi dfsxu
        if(now>n){
            cal();
            return;
        }
        for(int i=0;i<siz[1];++i){
           val[now]=i;
           dfs(now+1);
        }
    }
    void main(){
        //cout<<siz[1]<<endl;
        memset(val,0,sizeof val);
        memset(hasin,0,sizeof hasin);
        dfs(n);
        cout<<ans<<'\n';
    }
}

int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    while(T--){
        idx=0;
        dfn=0;
        memset(head,-1,sizeof head);
        cin>>n>>m;
        for(int i=2;i<=n;++i){
            int p;
            cin>>p;
            addedge(p,i);
        }
        memset(siz,0,sizeof siz);
        gets(1);
        BL::main();

    }
    return 0;
}
