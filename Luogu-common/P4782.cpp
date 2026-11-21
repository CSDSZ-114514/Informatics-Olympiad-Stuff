#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=4e6+10;
bool flag=false,ans[N];
long long dfn[N],low[N],scc[N],cnt,siz[N],tot;
stack<long long> s;
vector<long long> e[N];
void tarjan(long long u){
    dfn[u]=low[u]=++tot;
    s.push(u);
    for(long long v:e[u]){
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }else if(!scc[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(dfn[u]==low[u]){
        ++cnt;
        while(true){
            long long h=s.top();
            s.pop();
            scc[h]=cnt;
            siz[cnt]++;
            if(h==u){
                break;
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        long long x,a,y,b;
        cin>>x>>a>>y>>b;
        e[x+!a*n].push_back(y+b*n);
        e[y+!b*n].push_back(x+a*n);
    }
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++){
        if(scc[i]==scc[i+n]){
            flag=true;
            break;
        }else{
            if(scc[i]<scc[i+n]){
                ans[i]=0;
            }else{
                ans[i]=1;
            }
        }
    }
    if(!flag){
        cout<<"POSSIBLE"<<endl;
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
    }else{
        cout<<"IMPOSSIBLE";
    }
    return 0;
}