#include <bits/stdc++.h>
using namespace std;

int n,m,fr[175][175],ansx,ansy;
char ads[175][175];
struct Node{
	int x,y;
};queue<Node> q;
int dx[10]={2,2,1,-1,-2,-2,-1,1},dy[10]={1,-1,2,2,1,-1,-2,-2};
void bfs(){
	while(!q.empty()){
		Node u=q.front();
		q.pop();
		for(int i=0;i<8;i++){
			int fx=u.x+dx[i],fy=u.y+dy[i];
			if(fx>=1&&fy>=1&&fx<=n&&fy<=m){
				if((ads[fx][fy]=='.'||ads[fx][fy]=='H')&&fr[fx][fy]==-1){
					fr[fx][fy]=fr[u.x][u.y]+1;
					q.push({fx,fy});
					if(ads[fx][fy]=='H'){
						ansx=fx;ansy=fy;
						return ;
					}
				}
			}
		}
	}
	
}
int main(){
	cin>>n>>m;
	memset(fr,-1,sizeof(fr));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin>>ads[j][i];
			if(ads[j][i]=='K'){
				q.push({j,i});
				fr[j][i]=0;
			}
//			if(ads[j][i]=='H'){
//				ansx=j;ansy=i;
//			}
		}
	}
	bfs();
	cout<<fr[ansx][ansy];
	return 0;
}
