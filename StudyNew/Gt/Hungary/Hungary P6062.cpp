#include<bits/stdc++.h>
using namespace std;
long long r,c,cnth,cntl,ans;
bool mp[1005][1005];
long long h[1005][1005],l[1005][1005];
bool vis[1000005];
long long match[1000005];
vector<long long> ed[1000005];
bool hungary(long long u){
    for(long long t:ed[u]){
        if(vis[t])continue;
        vis[t]=1;
        if(!match[t]||hungary(match[t])){
            match[t]=u;
            return true;
        }
    }
    return false;
}
int main(){
    cin>>r>>c;
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            char t;cin>>t;
            if(t=='*'){
                mp[i][j]=1;
            }
            if(t=='.'){
                mp[i][j]=0;
            }
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(mp[i][j]==0)continue;
            if(j==1||mp[i][j-1]==0){
                cnth++;
            }
            h[i][j]=cnth;
        }
    }
    for(int j=1;j<=c;j++){
        for(int i=1;i<=r;i++){
            if(mp[i][j]==0)continue;
            if(i==1||mp[i-1][j]==0){
                cntl++;
            }
            l[i][j]=cntl;
        }
    }
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(mp[i][j]){
                ed[h[i][j]].push_back(l[i][j]);
            }
        }
    }
    for(int i=1;i<=cnth;i++){
        memset(vis,0,sizeof(vis));
        if(hungary(i)){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}