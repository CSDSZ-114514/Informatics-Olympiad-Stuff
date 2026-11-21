//基环树：由n个顶点和n条边构成的连通图，也就是在树的基础上增加一条边形成环，称为基环树
//基环树的解决方式： 
// 1. 将环断开一条边，做普通树处理
// 2. 将环上每个子树节点的信息合并到该节点上，然后对环进行处理 



//通过深搜找环 
void find(int u, int fa) {	
    vis[u] = 1;		
	for(int i:h[u]) {
		int v = e[i].v;
		if(v!=fa) {
			if(vis[v]) {
				idx = i;
			} else {	
				find(v, u);
			}
			
		} 
	}
}

//通过树形DP得到每个点选或不选得最大值 
void dfs(int u, int fa) {
	f[u][0] = 0;
	f[u][1] = 1;
	
	for(int i:h[u]) {
		int v = e[i].v;
		if(v!=fa) {
			if(i==idx || i==(idx^1)) continue;//不能是断边 
			
			dfs(v, u);
			f[u][1] += f[v][0];
			f[u][0] += max(f[v][0], f[v][1]);
		}		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) {
		int u;
		cin>>u;
		if(u==-1) continue;
		e.push_back({i,u}); //防止有重边，需要按编号进行存储 
		h[i].push_back(e.size()-1);
		e.push_back({u,i});
		h[u].push_back(e.size()-1); 
	}
	
	//如果是基环树森林，循环处理每一个基环树 
	for(int i=1; i<=n; i++) {
		if(!vis[i]) { 
			idx = -1; //存储环边的编号			
			find(i, i); //找环 
			
			if(idx!=-1 ) { //基环树 
				int r1 = e[idx].u;
				int r2 = e[idx].v;
				dfs(r1, r1); //环边上的两个点分别作为树根，进行树形DP处理 
				ll maxv = f[r1][0];
				dfs(r2, r2);
				maxv = max(maxv, f[r2][0]); //因为r1 r2 不可以同时存在，在两个根节点不选的情况中取最大值 
				sum += maxv;
			} else { //普通树 
				dfs(i, i);
				sum += max(f[i][0], f[i][1]);
			}
		}
	}

	cout<<sum<<"\n";
	return 0;
} 
