#include<bits/stdc++.h>
using namespace std;
long long K,n,m;
const long long N=2e5+6;
bool flag=false;
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
    cin>>K;
    while(K--){
        flag=false;
        memset(e,0,sizeof(e));memset(dfn,0,sizeof(dfn));
        memset(low,0,sizeof(low));memset(scc,0,sizeof(scc));
        memset(siz,0,sizeof(siz));
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char le1,le2;long long nu1,nu2;
            cin>>le1>>nu1>>le2>>nu2;
            long long nu3,nu4;
            if(le1=='m')nu3=1;if(le1=='h')nu3=0;
            if(le2=='m')nu4=1;if(le2=='h')nu4=0;
            e[nu1+!nu3*n].push_back(nu2+nu4*n);
            e[nu2+!nu4*n].push_back(nu1+nu3*n);
        }
        for(int i=1;i<=2*n;i++){
            if(!dfn[i]){
                tarjan(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(scc[i]==scc[i+n]){
                cout<<"BAD"<<endl;
                flag=true;
                break;
            }
        }
        if(!flag){
            cout<<"GOOD"<<endl;
        }
    }
    return 0;
}