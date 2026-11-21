//费用流：给定一个有向图，有源点S和汇点T, 每条边有容量c，流量f，和单位费用w
//求最大流情况下的最大费用和最小费用
//存反向边时，容量=0，费用=-w 
// EK算法：同样可行流的情况下，总费用最少，则当前增广路上的单位费用之和最少，
//将广搜寻找增广路改成spfa算法需要一条单位费用之和最少的增广路，即到源点的最短路

// 最大费用最大流：将每条边上的单位费用取反进行存储，则最终的最小费用取反为最大费用 

//最小费用最大流
//d[]: 到源点单位费用之和的最短路
//mf[]: 增广路上的容量上限 
bool spfa() {
	memset(d, 0x3f, sizeof(d));
	memset(mf, 0, sizeof(mf));
	
	d[s] = 0;
	q.push(s); //源点入队 
	vis[s] = 1;
	mf[s] = 1e9;
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = 0;
		
		for(int i:h[u]) {
			int v = e[i].v;			
			if(d[v] > d[u] + e[i].c && e[i].w) { //满足最短路&&剩余容量>0) 
				d[v] = d[u] + e[i].c; //更新最短路 
				mf[v] = min(mf[u], e[i].w); //更新容量 
				pre[v] = i; //保存边的编号 
				if(!vis[v]) {
					q.push(v);
					vis[v] = 1;
				}
			}
		}
	}
	
	return mf[t]>0;
	
}

int main() {
	cin>>n>>m>>s>>t;
	
	for(int i=1; i<=m; i++) {
		int u, v, w, c;
		cin>>u>>v>>w>>c;
		e.push_back({u,v,w,c}); //存正向边 
		h[u].push_back(e.size()-1);
		
		e.push_back({v,u,0,-c}); //存反向边 容量=0，费用=-w 
		h[v].push_back(e.size()-1); 
	}

	//循环找增广路 
	while(spfa()) {
		int v = t; //找到增广路更新残留网 
		while(v!=s) {
			int i = pre[v];
			e[i].w -= mf[t]; //更新正向边剩余容量 
			e[i^1].w += mf[t];//更新反向边剩余容量 
			v = e[i^1].v;
		}
		flow += mf[t]; //累加流量 
		sum += d[t]*mf[t]; //累加费用=单位费用之和*可行流  
	}

	return 0;
}


