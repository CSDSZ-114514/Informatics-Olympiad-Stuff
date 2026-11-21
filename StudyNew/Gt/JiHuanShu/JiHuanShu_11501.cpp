#include<bits/stdc++.h>
using namespace std;
long long n,f[1000005][5];
long long idx;
bool vis[1000005];
struct ED{
    long long u,v;
};
vector<ED> e; 
vector<long long> h[1000005];
void find(long long u,long long fa){
    vis[u]=1;
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
	f[u][1] = 1;
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
        long long c;cin>>c;
        if(c==-1){
            continue;
        }
        e.push_back({i,c});
	    h[i].push_back(e.size() - 1);
        e.push_back({c,i});
	    h[c].push_back(e.size() - 1);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            idx=-1;
            find(i,i);
            if(idx==-1){
                //memset(f, 0, sizeof(f));
                dfs(i,i);
                ans+=max(f[i][0],f[i][1]);
            }else{
                long long u=e[idx].u;
                long long v=e[idx].v;
                dfs(u,u);
                //memset(f, 0, sizeof(f));
                long long ans1=f[u][0];
                dfs(v,v);
                long long ans2=f[v][0];
                //memset(f, 0, sizeof(f));
                ans+=max(ans1,ans2);
            }
        }
    }
    cout<<ans;
    return 0;
}