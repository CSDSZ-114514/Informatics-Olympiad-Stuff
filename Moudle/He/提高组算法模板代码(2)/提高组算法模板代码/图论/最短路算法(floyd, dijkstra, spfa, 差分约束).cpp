//floyd 算法 时间复杂度O(n^3) 
// f[][]数组初始化最大值，f[i][i]=0, f[u][v]=w  
void floyd() {
	for(int k=1; k<=n; k++) {
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=n; j++) {
				//经过k点和不经过k点f[i][j]取最小值 
				f[i][j] = min(f[i][j], f[i][k]+f[k][j]); 
			}
		}
	}
}

—————————————————————————————————— 
//标准版 dijkstra 算法 时间复杂度O(n^2) , 不可以处理负边权
// n次处理，每次从n个元素中找到一个未计算出最短路且最小d值得点u，
//标识u点计算出最短路，并更新u得所有出边v得最短路 
void dijkstra(int s) {
	//初始化所有点的最短路为最大值，注意从0开始 
	for(int i=0; i<=n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0; //起点初始化为0 
	for(int i=1; i<=n; i++) { //枚举n次处理 
		int u=0;
		for(int j=1; j<=n; j++) {  
			if(!vis[j] && d[j] < d[u]) { //每次选取未计算出最短路径的最小d值 
				u=j;
			}
		}
		vis[u] =1; //更新u点计算出最短路径 
		for(Node t:e[u]) { //枚举u的所有出边 
			if(!vis[t.v] && d[t.v] > d[u]+t.w) { //如果v点经过u点的最短路径更短，则更新 
				d[t.v] = d[u] + t.w;
			}
		}
	}
} 

———————————————————————————————————— 
//dijkstra 堆优化版，时间复杂度 O(mlogm) ，不可以处理负边权 
//使用优先队列存储d值发生变更得点，每次取队首元素，即最小d值得点u
//标识u点计算出最短路，并更新u得所有出边v得最短路，如果v得最短路发生变更，插入优先队列 
struct Node{
	int u, dis;
	
	//权值越大，优先级越低 
	bool operator<(const Node p) const{
		return dis > p.dis; 
	} 
};
priority_queue<Node> q; //创建优先队列，存储d值发生变更的点 

void dijkstra(int s) {
	//初始化所有点的最短路为最大值 
	for(int i=1; i<=n; i++) {
		d[i] = inf;
	}
	d[s] = 0; //起点设置为0 
	q.push({s, 0}); //起点和最短路 入队 
	
	while(!q.empty()) {
		Node h = q.top(); //取出队首元素，当前元素的d值发生变更，且最小 
		q.pop();
		if(vis[h.u]) {
			continue;
		}
		vis[h.u] = 1; //更新当前点计算出最短路 
		for(Edge t: e[h.u]) { //枚举u的所有出边 
			if(!vis[t.v] && d[t.v] > d[h.u] + t.w) { //如果v点经过u点的最短路径更短，则更新   
				d[t.v] = d[h.u] + t.w;
				q.push({t.v, d[t.v]}); //更新的点入队 
			}
		}
	}
}

—————————————————————————————————— 
//spfa 算法 时间复杂度：O(km~nm),可以处理负边权
//将d值发生变更得点入队，每次取出队首元素u，更新出边v的最短路径
//如果v的最短路发生变更，则入队，一直到所有点的d值均不变更，最短路径确定 
void spfa(int s) {
	//初始化所有点的最短路为最大值 
	for(int i=1; i<=n; i++) {
		d[i] = inf;
	}
	d[s] = 0; //起点最短路更新为0 
	q.push(s); //起点入队 
	vis[s] = 1; //标识起点在队列 
	
	while(!q.empty()) {
		int u = q.front(); //取出队首元素 
		q.pop();
		vis[u] = 0; //标识队首元素不在队列 
		
		for(Node t:e[u]) { //枚举所有出边v 
			if(d[t.v] > d[u] + t.w) { //如果经过u点更优 
				d[t.v] = d[u] + t.w; //更新v点最短路 
				if(!vis[t.v]) { //如果v点不在队列 
					q.push(t.v); //入队 
					vis[t.v] = 1; //更新v点在队列 
				}
			}
		}
	}
} 

———————————————————————————————————————— 
//差分约束，用来求一组将不等式的解，将不等式转化为 v-u <= c(求最短路） v-u >=c (求最长路）
//将变量做为节点，创建u->v的有向边，值c做为边的权重
//根据题意，利用spfa算法求当前图的最短路(求最大解)或最长路(求最小解）
//当有向图有环时，不等式无解 
bool spfa(int s) {
	for(int i=1; i<=n; i++) {
		d[i] = inf;
	}
	d[s] = 0;
	vis[s] = 1;
	q.push(s);
	
	while(!q.empty()) {
		int u = q.front();
		q.pop();		
		vis[u] = 0;
		for(Node t: e[u]) {
			if(d[t.v] > d[u] + t.w) {
				d[t.v] = d[u] + t.w;
				if(!vis[t.v]) {
					vis[t.v] = 1;
					q.push(t.v);
				}
				//当有向图出现负环，不等式无解 
				cnt[t.v] = cnt[u] + 1; 
				if(cnt[t.v] > n) {
					return false;
				}
			}
		}
	}
	
	return true;
}
int main() {
	//将不等式转化为边，变量得值转换为求最短路径 
	// v-u <= w 
	e[v].push_back({u,w}); 
	
	//添加虚拟源点，非变量中的点 
	for(int i=1; i<=n; i++) {
		e[0].push_back({i, 0});
	}
	
	//当出现负环得时候没有解 
	if(spfa(0)) {
		for(int i=1; i<=n; i++) {
			cout<<d[i]<<" "; //d数组的值即为解 
		}
	} else {
		cout<<"NO";
	}
}

