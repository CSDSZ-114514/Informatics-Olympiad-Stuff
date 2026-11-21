#include<bits/stdc++.h>
using namespace std;
extern "C" bool move_to(char position);
bool vis[505][505],mp[505][505];
long long dx[4]={-1,1,0,0};
long long dy[4]={0,0,1,-1};
char mv[4]={'W','S','D','A'};
char mvv[4]={'S','W','A','D'};
bool init=true;
long long sx,sy;
long long N=0;
void dfs(long long x,long long y){
	for(int i=0;i<=3;i++){
		long long tx=x+dx[i];
		long long ty=y+dy[i];
		if(tx<=1||tx>=N||ty>=N||ty<=1)continue;
		if(vis[tx][ty])continue;
		vis[tx][ty]=true;
		if(move_to(mv[i])){
			mp[tx][ty]=false;
			dfs(tx,ty);
			move_to(mvv[i]);
			
		}
	}
}
extern "C" string find_out_map(int x,int y,int n){
	memset(vis,0,sizeof(vis));
	memset(mp,1,sizeof(mp));
	for(int i=1;i<=n;i++){
		vis[1][i]=true;
		vis[i][1]=true;
		vis[n][i]=true;
		vis[i][n]=true;
		mp[1][i]=true;
		mp[i][1]=true;
		mp[n][i]=true;
		mp[i][n]=true;
	}
	sx=x;sy=y;N=n;
	vis[x][y]=true;
	mp[x][y]=false;
	dfs(x,y);
	string s=""; 
	for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
        	s+=mp[i][j]?'1':'0';
    	}
	}
	return s;
}
