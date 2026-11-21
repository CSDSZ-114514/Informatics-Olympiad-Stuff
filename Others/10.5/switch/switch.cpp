#include<bits/stdc++.h>
using namespace std;
struct PT{
    long long x,y;
};
vector<PT> e[105][105];
queue<PT> q;
bool vis[105][105],canreach[105][105],vis2[105][105];
long long dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
void bfs(){
    while(!q.empty()){
        PT u=q.front();
        q.pop();
        for(PT v:e[u.x][u.y]){
            if(canreach[v.x][v.y])continue;
            else{
                canreach[v.x][v.y]=true;
                if(vis2[v.x][v.y]){
                    q.push({v.x,v.y});
                    vis[v.x][v.y]=false;
                }
            }
        }
        for(int i=0;i<=3;i++){
            long long tx=u.x+dx[i],ty=u.y+dy[i];
            vis2[tx][ty]=true;
            if(canreach[tx][ty]&&!vis[tx][ty]){
                q.push({tx,ty});
                vis[tx][ty]=true;
            }
        }
    }
}
long long n,m;
int main(){
    freopen("switch.in","r",stdin);
    freopen("switch.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        long long x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        e[x1][y1].push_back({x2,y2});
    }
    q.push({1,1});
    vis[1][1]=true;canreach[1][1]=true;
    bfs();
    long long ans=0;
    //for(int i=1;i<=n;i++){for(int j=1;j<=n;j++){cout<<vis[i][j]<<" ";}cout<<endl;}
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(canreach[i][j])ans++;
    cout<<ans;
}