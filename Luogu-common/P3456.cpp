#include<bits/stdc++.h>
using namespace std;
const long long N=1e3+5;
long long n,w[N][N];
long long dx[10]={1,1,1,0,-1,-1,-1,0};
long long dy[10]={1,0,-1,1,1,0,-1,-1};
bool vis[N][N];
struct pt{
    long long x,y;
};
queue<pt> q;
void bfs(long long sx,long long sy){
    long long minh=1e9;bool flag=false;
    for(int i=0;i<8;i++){
        long long tx=sx+dx[i];
        long long ty=sy+dy[i];
        if(tx<1||tx>n||ty<1||ty>0)continue;
        //if(vis[tx][ty])continue;
        if(w[tx][ty]==w[sx][sy])continue;
        if(i!=0&&((w[sx][sy]<minh&&w[sx][sy]>w[tx][ty])||(w[sx][sy]>minh&&w[sx][sy]<w[tx][ty]))){
            flag=true;
            break;
        }
        minh=min(minh,w[tx][ty]);
    }
    if(flag)return ;
    q.push({sx,sy});
    while(!q.empty()){
        pt u=q.front();
        for(int i=1;i<8;i++){
            long long tx=u.x+dx[i];
            long long ty=u.y+dy[i];
            if(tx<1||tx>n||ty<1||ty>0)continue;
            if(w[tx][ty]!=w[u.x][u.y])continue;
            if(vis[tx][ty])continue;
            if(flag)continue;
            vis[tx][ty]=true;
            q.push({tx,ty});
            minh=1e9;
            for(int j=0;j<8;j++){
                long long ttx=tx+dx[i];
                long long tty=ty+dy[i];
                if(ttx<1||ttx>n||tty<1||tty>0)continue;
                if(w[ttx][tty]==w[tx][ty])continue;
                if(j!=0&&((w[tx][ty]<minh&&w[tx][ty]>w[ttx][tty])||(w[tx][ty]>minh&&w[tx][ty]<w[ttx][tty]))){
                    flag=true;
                    break;
                }
                minh=min(minh,w[tx][ty]);
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(!vis[i][j]){
                vis[i][j]=true;
                bfs(i,j);
            }
        }
    }
    return 0;
}