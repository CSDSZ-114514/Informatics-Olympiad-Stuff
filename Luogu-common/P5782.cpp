#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+6;
long long n,m;
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
        long long a,b;
        cin>>a>>b;
        if(b%2==1){
            e[a].push_back(b+1);
        }else{
            e[a].push_back(b-1);
        }
        if(a%2==1){
            e[b].push_back(a+1);
        }else{
            e[b].push_back(a-1);
        }
    }
    for(int i=1;i<=2*n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i=1;i<=2*n;i+=2){
        if(scc[i]==scc[i+1]){
            cout<<"NIE"<<endl;
            return 0;
        }
    }
    for(int i=1;i<=2*n;i+=2){
        if(scc[i]==scc[i+1]){
            cout<<"NIE"<<endl;
            break;
        }else{
            if(scc[i]>scc[i+1]){
                cout<<i+1<<endl;
            }else{
                cout<<i<<endl;
            }
        }
    }
    return 0;
}