//网络流：在一个有向图中，有源点S和汇点T，每条边有流量f和容量c，可行流应满足：
// 1. 每条边的流量 f<=c   2. 除源点和汇点外，每个点的流入总量=流出总量
//求在所有可行流中的最大流量（最大流）

//为了提供退流管道，每条有向边存储的时候，同时存储反向边（容量=0） 
// 循环寻找增广路：保证每条边的剩余容量>=0，
//然后更新残留网：正向边容量 -= 可行流  反向边容量+=可行流 


//EK算法：通过广搜bfs循环找增广路，然后更新残留网，累计可行流 （一次处理一条增广路） 
//时间复杂度O(n*m^2) 

// mf[]: 存储从源点s到当前点增广路上的容量上限（最小容量） 
bool bfs() {
	memset(mf, 0, sizeof(mf));
	queue<int> q;
	mf[s]= 1e9;
	q.push(s); //将源点s入队，进行广搜 
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		//如果访问到汇点t，则找到增广路 
		if(u==t) {
			return true;
		}
		
		//枚举所有出边 
		for(int i:h[u]) {
			int v = e[i].v; //获取当前出边节点 
			if(mf[v]==0 && e[i].w != 0) { //没被访问，且剩余容量>0
				mf[v] = min(mf[u], e[i].w); //更新到v点的容量最小值 
				pre[v] = i; //保存增广路访问v点是第几条表，为了找反向边 
				q.push(v); //将v入队 
			}
		}
	}
	return false; //没找到增广路 
}
int main() {
	for(int i=1; i<=m; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		e.push_back({u,v,w}); //保存正向边 
		h[u].push_back(e.size()-1); //为了更新残留网，保存边的编号 
		e.push_back({v,u,0}); //保存反向边，容量为0 
		h[v].push_back(e.size()-1);
	}
		
	while(bfs()) { //寻找增广路 
		int v = t;
		while(v != s) { //更新残留网 
			int i = pre[v];
			e[i].w -= mf[t]; //正向边更新剩余容量 
			e[i^1].w += mf[t]; //反向边更新可回退流量 
			v = e[i].u;
		}
		flow += mf[t];	//累计可行流，得到最大流 
	}

	return 0;
}



//Dinic算法 ：先通过广搜进行分层，然后通过深搜一次处理多条增广路，
//在深搜过程中更新残留网 ，时间复杂度O(m*n^2) 

//点进行分层 
//d[u]: 节点u的层次，源点s在第一层 
bool bfs() {
	memset(d, 0, sizeof(d));
	queue<int> q;
	q.push(s); //源点入队 
	d[s] = 1;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		
		//访问汇点t，则找到增广路 
		if(u==t) {
			return true;
		}
				
		for(int i:h[u]) {
			int v = e[i].v;
			if(d[v]==0 && e[i].w) { //当前点没被访问且容量>0 
				d[v] = d[u] + 1; //更新层 
				q.push(v);
			}
		}
	}
	
	return false; //没有找到增广路 
}

//根据分层，从u点出发寻找多条增广路，mf：从u能够流出的最大流量，返回值：从u流出的实际流量和
//寻找增广路和更新残余网同时进行 
ll dfs(int u, ll mf) {
	if(u==t) { //到达终点返回 
		return mf;
	}
	
	ll sum = 0; //存储从u流出的流量和
	//遍历所有出边
	for(int i:h[u]) { 
		int v = e[i].v;
		
		if(d[v] == d[u] + 1 && e[i].w) { //根据bfs更新的层数进行访问 && 有剩余容量 
			ll f = dfs(v, min(mf, e[i].w)); //基于v做深搜，获得能够处理的最大流量			
			e[i].w -= f; //更新当前边剩余流量 
			e[i^1].w += f; //更新反向边容量 
			sum += f; //更新流出总流量 
			mf -= f; //更新当前点的剩余流量 
			if(mf == 0) { //剩余为0， 余量优化退出 
				break;
			}
		}
	} 

	return sum;
} 
int main() {
	for(int i=1; i<=m; i++) {
		int u, v, w;
		cin>>u>>v>>w;
		e.push_back({u,v,w}); //存储正向边 
		h[u].push_back(e.size()-1);
		e.push_back({v,u,0});  //存储反向边 
		h[v].push_back(e.size()-1);
	}
		
	while(bfs()) { //对点分层，寻找增广路 
		flow += dfs(s, 1e9);  //累计网络流 
	}

	cout<<flow; 
	return 0;
}





