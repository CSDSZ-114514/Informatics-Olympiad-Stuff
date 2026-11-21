#include<bits/stdc++.h>
using namespace std;
long long m,f[505][505],g[505][505];bool fl=1;

int dx4[4] = { -1,1,0,0 };
int dy4[4] = { 0,0,-1,1 };
struct Node{
	int x,y,t;
};
queue<Node> q;
void bfs_xy4() { 
	while (!q.empty()) {
		Node temp = q.front();
		q.pop();
		for (int i = 0; i <= 3; i++) {
			int tx = temp.x + dx4[i];
			int ty = temp.y + dy4[i];
			int tt = temp.t+1;
			if (tx >= 0 && ty >= 0) {
				if (tt<f[tx][ty]&&g[tx][ty]==0) {
					q.push({ tx,ty,tt });
					g[tx][ty]=tt;
					if(f[tx][ty]>=100000){
						cout<<tt;
						fl=0;
						return;
					}
				}
			}
		}
	}
}
int main(){
	cin>>m;
	memset(f,127,sizeof(f));
	for(int i=1;i<=m;i++){
		long long  a,b,c;
		cin>>a>>b>>c;
		f[a][b]=min(f[a][b],c);
		f[a+1][b]=min(f[a+1][b],c);
		f[a][b+1]=min(f[a][b+1],c);
		if(a==0&&b==0){
			continue;
		}
		if(a==0){
			f[a][b-1]=min(f[a][b-1],c);
		}
		if(b==0){
			f[a-1][b]=min(f[a-1][b],c);
		}
		if(a!=0&&b!=0){
			f[a-1][b]=min(f[a-1][b],c);
			f[a][b-1]=min(f[a][b-1],c);
		}
	}
	q.push({0,0,0});
	bfs_xy4();
	if(fl){
		cout<<-1;
	}
	return 0;
}
