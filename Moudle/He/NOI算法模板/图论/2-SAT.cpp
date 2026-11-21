//2-SAT问题：给出n个变量xi，每个变量只能取0/1，给出m个条件，诸如 xi=0/1 或xj=0/1，
//求2-SAT问题的解，就是求出满足m个条件的一组x。 
//算法步骤：
// 1. 把逻辑关系转化为蕴含关系：例如 aVb -> !b -> a && !a->b
// 2. 拆点建图，把n个点拆成2n个点，例如 i对应 xi=0, i+n 对应xi=1,
//     通过蕴含关系连有向边  i+!a*n -> j+b*n   j+!b*n -> i+a*n
// 3. 在创建的有向图中进行tarjan缩点，如果scc[i] == scc[i+n], 则无解
//    如果 scc[i] < scc[i+n] 则xi=0, 否则 xi=1;

//Tarjan算法进行有向图缩点 
void tarjan(int u) {
	dfn[u] = low[u] = ++tot;
	st.push(u);
	for(int v: e[u]) {
		if(!dfn[v]) { //子结点没访问 
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if(!scc[v]) { //已访问但还未确定强连通分量 
			low[u] = min(low[u], dfn[v]);
		}
	}
	//当前点是环的入口 
	if(dfn[u] == low[u]) {
		cnt++;
		while(true) {
			int v = st.top(); //从栈顶元素开始到当前元素为止，都属于一个强连通分量 
			st.pop();
			scc[v] = cnt;
			if(v==u) {
				break;
			}
		}
	}
}
int main() {
	cin>>n>>m;
	for(int t=1; t<=m; t++) {
		int i, a, j, b;
		cin>>i>>a>>j>>b; //条件：xi=a || xj=b 
		e[i+!a*n].push_back(j+b*n); //把或关系转化为蕴含关系 !(xi=a) -> xj=b;
		e[j+!b*n].push_back(i+a*n); //把或关系转化为蕴含关系 !(xj=b) -> xi=a;
	}
	
	//对每个点运行tarjan算法，进行缩点 
	for(int i=1; i<=2*n; i++) {
		if(!dfn[i]) {
			tarjan(i);
		}
	}
	
	//如果点 i和i+n在一个分量中，即在一个环中，则无解 
	for(int i=1; i<=n; i++) {
		if(scc[i] == scc[i+n]) {  
			cout<<"IMPOSSIBLE";
			return 0;
		}
	}
	
	cout<<"POSSIBLE"<<endl;
	for(int i=1; i<=n; i++) {
		cout<< (scc[i]>scc[i+n]?1:0)<<" "; //根据i和i+n所在分量的大小输出结果 
	}
	
	return 0;
}  
