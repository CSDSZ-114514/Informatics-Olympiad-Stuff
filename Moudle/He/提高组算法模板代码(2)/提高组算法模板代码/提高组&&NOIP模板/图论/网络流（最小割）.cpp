//在有向图中，切一刀，将所有点划分为S和T集合，称为割，对于任意一个割，都可以使网络断流
//割的容量是指从S到T出边的容量之和，容量之和最小的割就是最小割
//最小割定理：最大流 = 最小割
//最小割的划分：求出最大流后，在残留网上进行搜索，从源点S出发，能够到达的属于A集合
//不能到达的属于B集合
//最小割的最少边： 求出最大流后，重新建图，满流的边的容量设为1，不满流的边容量设为无穷大
//在图上跑最大流，最大流的值就是最小割的边数

//广搜分层 
bool bfs(){
	queue<int> q;
	memset(d, 0, sizeof(d));
	d[s] = 1; //源点在第一层 
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		if(u == t) {
			return true;
		}
		
		for(int i:h[u]) {
			int v = e[i].v;
			if(d[v] == 0 && e[i].w) { //未访问且剩余容量>0 
				d[v] = d[u]+1;
				q.push(v);
			}
		}
	}
	
	return false;
}

//深搜查找多条增广路，对于u点，输入流是mf，返回最大输出流 
int dfs(int u, int mf) {
	if(u==t) {
		return mf;
	}
	
	int sum = 0;
	for(int i:h[u]) { //遍历所有出边 
		int v = e[i].v;
		if(d[v] == d[u]+1 && e[i].w) { //如果v点在u的下一层且剩余容量>0 
			int f = dfs(v, min(mf, e[i].w)); //遍历子结点v，并返回流入的最大流量 
			e[i].w -= f; //正向边更新剩余容量 
			e[i^1].w += f; //反向边更新剩余容量 
			sum += f; //统计总容量 
			mf-=f; //更新剩余容量 
			if(mf == 0) {
				break;
			}
		}
	}
	return sum;
}
 
int main() {
	cin>>n>>m;
	
	s = 1, t= n;
	for(int i=1; i<=m; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		e.push_back({u,v,w}); //正向边 
		h[u].push_back(e.size()-1);
		e.push_back({v,u,0}); //反向边，容量为0 
		h[v].push_back(e.size()-1); 
	} 
	
	//最小割 == 最大流 
	while(bfs()) {
		ans += dfs(s, 1e9); //使用dinic算法计算最大流 
	}
	
	cout<<ans<<" ";
	
	//重新建图，将满流的边设成1，其他边设置成无穷大，求最大流
	//最大流则为最小割的最小边数 
	for(int i=0; i<m; i++) {
		if(e[2*i].w == 0) {
			e[2*i].w = 1;
			e[2*i+1].w=0;
		} else {
			e[2*i].w = 1e9;
			e[2*i+1].w=0;
		}
	}
	
	//求最大流，最大流的值=最小割的最少边 
	int ans = 0;
	while(bfs()) {
		ans += dfs(s, 1e9);
	}
	
	cout<<ans;

	return 0;
} 
