//二分图最大匹配：在二分图中，任意两条边都没有公共节点，称为二分图的一组匹配
// 包含边数最多的一组匹配称为二分图最大匹配
//匈牙利算法：通过深搜dfs不停的找增广路来增加匹配边，找不到增广路时，达到最大匹配

//最小点覆盖：二分图中选取最少的点数，使这些点和所有的边都有关联
// 定理：最小点覆盖 = 二分图最大匹配数 
 
//vis[]: 用于在每次寻找增广路的过程中B集合中的点是否被访问 
// match[]：二分图中B集合中的每个点匹配的A集合的哪个点 
bool dfs(int u) {
	for(int v:e[u]) {
		if(vis[v]) continue; //子结点访问过不处理 
		vis[v] = 1; //标识访问过 
		
		//判断u和v是否能够匹配 
		if(!match[v] || dfs(match[v])) { //如果没匹配，或匹配的点能够让出来 
			match[v] = u; 
			return true; //能匹配返回true 
		}
	}
	return false; //不能匹配 
}
int main() {
	cin>>n>>m>>E;
	for(int i=1; i<=E; i++) {
		int u, v;
		cin>>u>>v;
		e[u].push_back(v); //为了防止二分图的A集合和B集合节点混乱，保存成有向图 
	}
	
	//遍历A集合的每一个点，尝试找到增广路进行匹配 
	for(int i=1; i<=n; i++) {
		memset(vis, 0, sizeof(vis)); //每次dfs前重置 
		if(dfs(i)) { //枚举每一个点是否能被匹配 
			ans++; //每找到新的一条增广路，匹配的边数增加1 
		}
	}
	
	cout<<ans;

	return 0;
}
