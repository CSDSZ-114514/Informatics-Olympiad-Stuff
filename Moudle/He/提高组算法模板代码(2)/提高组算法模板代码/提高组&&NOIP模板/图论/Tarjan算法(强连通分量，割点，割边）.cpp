//Tarjan算法：深搜维护 dfn[]: low[] 
//dfn[u]: 深搜时，u点是第几个被深搜到的
//low[u]：u点在图中可以访问的最小的dfn值 
void tarjan(int u) {
	dfn[u] = low[u] = ++tot; //初始化为自增变量tot 
	
	for(int v:e[u]) { //遍历u的所有出边 
		if(!dfn[v]) { //如果当前边没被访问过 
			tarjan(v); //基于v点继续做深搜 
			low[u] = min(low[u], low[v]); //v点返回时，用low[v] 更新low[u] 
		} else { //如果当前点被访问 
			low[u] = min(low[u], dfn[v]); //用dfn[v]更新low[u] 
		}
	}
} 
 
—————————————————————————————————— 
//Tarjan算法求强连通分量
//强连通分量：有向图中任意两点可以相互到达的最大子图，存在最大环 
//当u点深搜完成，如果dfn[u] == low[u]，说明在搜索树中，u点为根的子树没有后向边和交叉边，形成最大环
//则找到强连通分量 
//dfn[u]: 深搜时，u点是第几个被深搜到的
//low[u]：u点在图中可以访问的最小的dfn值 
//scc[u]: u点属于哪个强连通分量  
//siz[cnt] : 当前强连通分量的元素个数
 
void tarjan(int u) {
	dfn[u] = low[u] = ++tot; //初始化dfn和low数组 
	s.push(u); //为了标识强连通分量，当前点入栈 
	
	for(int v:e[u]) { //遍历u的所有出边v 
		if(!dfn[v]) { //当前点没被访问 
			tarjan(v); 
			low[u] = min(low[u], low[v]); // low[v]更新 low[u]
		} else if(!scc[v]) {//如果已访问且未求出强连通分量
			low[u] = min(low[u],dfn[v]); //用dfn[v] 更新low[u] 
		} 
	}
	
	//如果两个相等，在搜索树中，则以u为根的子树形成独立最大环，u为强连通分量根节点
	if(dfn[u] == low[u]) { 
		++cnt; //强连通分量个数 +1 
		while(true) {
			int h = s.top(); //从当前栈顶元素开始出栈，一直到u为止，都属于当前强连通分量 
			s.pop();
			scc[h] = cnt; //标识当前点的强连通分量编号 
			siz[cnt]++; //保存强连通分量元素个数 
			if(h == u) { //直到u出栈结束 
				break;
			}
		}
	}
}

————————————————————————————————————
//Tarjan算法求强连通分量缩点
//将有向图的每一个强连通分量缩成一个点，点的编号是强连通分量的编号
//根据新点建图，则新图里没有环

int main() {
	//不能保证图连通，基于每个点做tarjan算法 
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	
	for(int u=1; u<=n; u++) {//遍历每一个点 
		nw[scc[u]]+= w[u]; //维护新节点的权重（根据题意） 
		for(int v:e[u]) { //遍历当前点的所有出边 
			if(scc[u] != scc[v]) {//如果当前两个点不在一个强连通分量上 
				g[scc[u]].push_back(scc[v]); //基于强连通分量创建新图 
				d[scc[v]]++; //更新新节点的入度（根据题意）
			}
		}
	}
} 
 
—————————————————————————————————— 
//Tarjan算法求割点
//割点：在无向图中，删除当前点，连通块增加了，则当前点是割点
//对 u点做深搜，如果u点存在一个子节点v，low[v]>=dfn[u]，说明不经过u点，
//在搜索树中，以v为根的子树不能访问其它点，则u是割点（根节点需要两个这样的子节点） 

// dfn[] low[]  cut[u]:u是否为割点 
void tarjan(int u) {
	dfn[u] = low[u] = ++tot;//初始化 
	int child = 0;
	for(int v:e[u]) { //遍历u的所有出边 
		if(!dfn[v]) { //如果当前点v没被访问 
			tarjan(v);
			low[u] = min(low[u], low[v]);//low[v] 更新 low[u]	
			//存在子节点满足条件	
			if(low[v] >= dfn[u]) {  
				child++; //更新子节点个数 
				if(u!=root || child >=2) { //如果是根需要两棵子树满足条件 
					cut[u] = 1; //标识当前节点u是割点 
				}
			}
		} else { //如果当前点被访问 
			low[u] = min(low[u], dfn[v]); //用dfn[v] 更新low[u] 
		}
	}
} 

———————————————————————————————— 
//Tarjan算法求点双连通分量：无向图中不存在割点的极大点双连通子图 
//每个割点和满足条件的子节点构成了一个点双连通分量， 
// 发现满足条件的子节点是，从栈顶元素到当前子节点v全部出栈，
//并统计到一个点双连通分量中，当前节点u也属于当前分量 
//dfn[] low[] tot
//dcc[]: 标识每个点双连通分量里包含哪些元素 
void tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	st.push(u); //为了保存点双连通分量，当前点入栈 

	int child = 0;
	for(int v:e[u]) {
		if(!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
			//当子节点满足条件 
			if(low[v] >= dfn[u]) {
				child++;
				if(u!= root || child>1) {
					cut[u] = 1;
				}
				
				cnt++; //当找到满足条件的子节点新的点双连通分量 
				while(true) {
					int x = st.top(); //从栈顶元素开始到当前子节点为止全部出栈 
					st.pop();
					dcc[cnt].push_back(x); //将栈内元素放到一个点双连通分量中 
					if(x==v) {
						break;
					}
				}
				dcc[cnt].push_back(u); //当前节点u也属于当前分量 
			}
		} else {
			low[u] = min(low[u], dfn[v]);	
		}
	}
}  

—————————————————————————————————— 
//Tarjan算法求割边
//割边：对于无向图，删除一条边后连通块增加了，则当前边是割边
// 对节点u进行深搜时，保证不能以原边访问回父节点时，
// 如果存在子节点 low[v] > dfn[u], 说明不经过原边u-v这条边，
//子节点不能访问u之前的其它点，因此u-v这条边是割边 
 
//dfn[] low[] tot
//边的存储 vector<Node> e   vector<int> h[u]：存储u的出边是第几条边 
void tarjan(int u, int inEdge) { //inEdge:父边的编号 
	dfn[u] = low[u] = ++tot;
	
	for(int j: h[u]) {
		int v = e[j].y;
		if(!dfn[v]) {
			tarjan(v, j);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) { //存在子节点满足条件 
				bri[j] = bri[j^1] = 1; //标识当前边是割边 
			}
		} else if(j != (inEdge^1)) { //不是指向回边 
			low[u] = min(low[u], dfn[v]);
		}
	} 
} 
int main() {
	
	for( ) {
		cin>>u>>v;
		e.push_back({u,v}); //存u->v的边 
		h[u].push_back(e.size()-1); //添加u的出边，存储在e中的索引 
		e.push_back({v,u}); //存v->u的边 
		h[v].push_back(e.size()-1); //添加v的出边，存储在e中的索引 
	}
	
	for(int i=1; i<=n; i++) {
		if(!dfn[i]) {
			tarjan(i, 0); 
		} 
	} 
} 

—————————————————————————————————— 
//Tarjan算法求边双连通分量：无向图中不包含割边的极大边双连通子图，
//边双连通分量中的任意两个点之间都有两条路径可以到达 
//当u深搜结束，以不能访问父节点回边的方式进行遍历，
//当 dfn[u] == low[u] 时，说明不经过父边，不能访问其他节点，
//则当前节点与父节点之间的边是割边，当前节点是边双连通分量的起点 
//dfn[] low[] tot
//dcc[u]: u点属于哪个边双连通分量 
//边的存储 vector<Node> e   vector<int> h[]
void tarjan(int u, int in_edge) {
	dfn[u] = low[u] = ++tot;
	st.push(u);//当前点入栈 
	for(int j: h[u]) {
		int v = e[j].y;
		if(!dfn[v]) {
			tarjan(v, j);
			low[u] = min(low[u], low[v]);
			if(low[v] > dfn[u]) { //存在子节点满足条件，u-v这条边是割边 
				bri[j] = bri[j^1] = 1; //更新边是桥 
			}
		} else if(j != (in_edge^1)) { //不能往回走 
			low[u] = min(low[u], dfn[v]);
		}
	}
	
	if(dfn[u] == low[u]) { //当前点是边双连通分量入口 
		cnt++;
		while(true) {
			int v = st.top(); //从栈顶到当前节点u都属于同一个分量 
			st.pop();
			dcc[v] = cnt;
			if(v==u) break;
		}
	} 
}

