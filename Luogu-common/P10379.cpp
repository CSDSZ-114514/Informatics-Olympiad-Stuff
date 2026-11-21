#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1005][1005],vis[1005][1005],ans;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
map<string,int> mp;string s = "";
void dfs(int x,int y){
	for(int i=0;i<4;i++){
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (tx>0&&tx<=n&&ty>0&&ty<=m){
			if((!vis[tx][ty])&&(a[tx][ty]==a[x][y])){
				s += char(i + '0'); 
				vis[tx][ty] = 1; 
				dfs(tx,ty);
			}
		}
		s+=' ';
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for (int i = 1;i <= n;i++){
		for (int j = 1;j <= m;j++){
			if (!vis[i][j]) {
				s.clear();
				vis[i][j] = 1;
				dfs(i,j);
				if (!mp[s]) {
					ans++;
					mp[s]=1; 
				}
				
			}
		}
	}
	cout<<ans;
	return 0;
}
