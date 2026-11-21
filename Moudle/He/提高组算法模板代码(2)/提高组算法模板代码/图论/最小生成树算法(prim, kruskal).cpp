//prim 算法  时间复杂度O(n^2)
//进行n次处理，每次从未加入最小生成树的点中取最小的d值点u
//标识u点加入最小生成树，更新u得所有出边v点
//如果经过u点 d值更小，则更新 

int prim(int s) {
	//初始化所有点与已经加入最小生成树点连通得d值为最大值 
	for(int i=0; i<=n; i++) {
		d[i] = 1e9;
	}
	d[s] = 0; //起点距离为0； 
	int sum = 0;
	for(int i=1; i<=n; i++) { //枚举n次 
		int u=0;
		for(int j=1; j<=n; j++) {
			//找一个未加入最小生成树且最小得d值 
			if(!vis[j] && d[j] < d[u]) {
				u = j;
			}
		}
		vis[u] = 1; //更新u加入最小生成树 
		sum += d[u];
		for(Node t:e[u]) { //枚举所有出边 
			if(!vis[t.v] && d[t.v] > t.w) { //如果v点经过u与最小生成树其它点连通更优则更新 
				d[t.v] = t.w;
			}
		}
	}
	return sum;
}

———————————————————————————————— 
//kruscal 算法  ，时间复杂度 O(mlogm)
//将m条边按权重从小到大排序，按顺序处理每条边，
//如果当前边不和已经被选中得边成环，则当前边被选
//n个点需要n-1条边
//并查集查到x所在集合得根节点 
int find(int x) {
	if(x == fa[x]) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}

int kruskal() {
	//并查集初始化 
	for(int i=1; i<=n; i++) {
		fa[i] = i;
	}
	
	//所有节点按权重从小到大排序 
	sort(a+1, a+m+1, cmp);
	
	int sum = 0;
	for(int i=1; i<=m; i++) { //依次处理m条边 
		int x = find(a[i].u); //并查集查询当前边两个节点所在集合的根节点 
		int y = find(a[i].v);
		if(x != y) { //判断当前边得两个节点是否在同一集合，如果不是 
			sum += a[i].w; //选用当前边 
			fa[x] = y; //将两个集合合并 
		}
	}
	return sum;
}

