#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
//#include<bits/stdc++.h>
#include<queue> 
#include<map> 
#define LL long long
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
bool g[1005][1005],f[1005][1005];
int m,n;
void dfs_xy(int x,int y){
	for(int i=0;i<=3;i++){
		int tx = x+dx[i];
		int ty = y+dy[i];
		if (tx>=1&&tx<=n&&ty>=1&&ty<=m){
			if(f[tx][ty]==0&&g[tx][ty]==1){
				f[tx][ty]=1;
				dfs_xy(tx,ty);
			}
		}
	}
}
int main(){
	char temp;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>temp;
			if(temp == '.'){
				g[i][j]=1;
			} else {
				g[i][j]=0;
			}
		}
	}
	f[1][1]=1;
	dfs_xy(1,1);
	if(f[n][m]==1){
		cout<<"YES";
	}else{
		cout<<"NO";
	}
}
