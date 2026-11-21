//深搜：递归处理，对于每一个u，从所有能够访问的节点中找一个能访问且没被访问的节点进行访问
//然后基于新点继续做深搜
//深搜处理的问题：图的遍历，连通块问题，所有路径问题 

//二维数组存图，普通图的深搜，时间复杂度 O(n^2)
//如果使用vector存图，时间复杂度 O(n+m) 
void dg(int x) {
	for(int i=1; i<=n; i++) {
		if(g[x][i] == 1 && f[i] == 0) {
			f[i]=1;
			dg(i);
		}
	}	
}

//网格图的深搜 
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void dfs(int x, int y) {
	for(int i=0; i<4; i++) {
		int tx =x + dx[i];
		int ty =y + dy[i];
		
		if(tx>0 && tx<=n && ty>0&& ty<=m) {
			if(f[tx][ty] == 0 && g[tx][ty] == '.') {
				f[tx][ty]=1;
				dfs(tx,ty);
			}
		}
	}	
}

//深搜求所有路径, 注意状态还原 
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void dg(int x, int y) {
	if(x == ex && y == ey) { //到达终点深搜结束 
		ans++;
		return;		 
	} 
	
	for(int i=0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(tx>0 && tx <=n && ty>0&& ty<=n) {
			if(g=[tx][ty] != 1 && f[tx][ty] == 0) {
				f[tx][ty] = 1;
				dg(tx, ty);
				f[tx][ty] = 0; // 路径问题，状态需要还原 
			}
		}		
	}
} 

————————————————————————————————————
//广搜：对于每个节点，遍历完所有出边，在根据遍历顺序处理每个节点
// 采用队列，将起点入队，每次取出队首元素，遍历所有出边，如果能访问且没访问，则访问且入队
// 广搜处理问题：连通性，连通块，最短路径问题（边没有权重） 

//普通图广搜 
void bfs( ) {
	f[1] = 1;
	q.push(1);
	 
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		for(int i=1; i<=n; i++) {
			if(g[u][i] == 1 && f[i] == 0) {
				f[i] = 1;
				q.push(i);
			}
		}
	}
}

//网格图广搜 
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
queue<Node> q;

void bfs() {
	f[1][1] = 1;
	q.push({1,1}); 
	
	while(!q.empty()) {
		Node u = q.front();
		q.pop();
		for(int i=0; i<4; i++) {
			int tx = u.x + dx[i];
			int ty = u.y + dy[i];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=m) {
				if(g[tx][ty] != '*' && f[tx][ty] == 0) {
					f[tx][ty] = 1;
					q.push({tx,ty});
				}
			}
			
		}
	}
}

//最短路径问题：
queue<Node> q;
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
void bfs() {
	memset(f,-1,sizeof(f)); //初始为-1，代表没访问 
	f[1][1] = 0;  //起点初始为0 
	q.push({1,1});	
	 
	while(!q.empty()) {
		Node u = q.front();
		q.pop();
		for(int i=0; i<8; i++) {
			int tx = u.x + dx[i];
			int ty = u.y + dy[i];
			if(tx>=1&&tx<=n&&ty>=1&&ty<=n) {
				if(g[tx][ty] == 0 && f[tx][ty] == -1) {
					f[tx][ty] = f[u.x][u.y]+1; //访问时更新最短路径 
					q.push({tx,ty});
				}
			}
			
		}
		
	}
} 









 
