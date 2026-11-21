//根据倍增法求树上LCA (最近公共祖先）

//dep[u]: u的深度 
//fa[u][i]:节点u，向上跳2^i步的编号 
//预处理，求 dep[u], fa[u][i] 
void dfs(int u, int father) {
	dep[u] = dep[father] + 1;
	fa[u][0] = father;
	
	for(int i=1; i<=20; i++) {
		fa[u][i] = fa[fa[u][i-1]][i-1]; //倍增法求fa[u][i] 
	}
	
	for(int v:e[u]) {
		if(v != father) {
			dfs(v, u);
		}
	}
}

//求u,v的最近公共祖先 
int lca(int u, int v) {
	//保证dep[u]>=dep[v] 
	if(dep[u] < dep[v]) {
		swap(u, v);
	}
	
	//统一深度, 层数由高到低判断，只要保证跳后 dep[u] >=dep[v]，则跳 
	for(int i=20; i>=0; i--) {
		if(dep[fa[u][i]] >= dep[v]) {
			u = fa[u][i];
		}
	}
	
	if(u==v) {
		return u;
	}
	
	//找最近祖先结点的下一层节点，层数由高到低判断，只要跳后 u!=v，则跳 
	for(int i=20; i>=0; i--) {
		if(fa[u][i] != fa[v][i]) {
			u = fa[u][i];
			v = fa[v][i];
		}
	} 
	
	return fa[u][0]; //u向上跳一步就是最近公共祖先 
}

——————————————————————————————————————————
//树形DP：在树形结构上进行动态规划，当给定一棵树，求极值时，可以考虑树形DP。
//状态通常定义为以当前节点为根的子树的某种性质，采用深度优先遍历的方式进行，回溯时用子节点更新父节点。 
void dfs(int u, int fa) {
	f[u][1] = 1; //初始化 
	for(int v:e[u]) {
		if(v != fa) { //当树是无根树时，需要判断v不是u的父节点 
			dfs(v, u); //基于v做深搜 
			f[u][0] += f[v][1]; //当子结点处理完成，回溯时用子结点的状态更新父节点 
			f[u][1] += min(f[v][1], f[v][0]);
		}		
	}
}

——————————————————————————————————————————
//树得直径：树上任意两节点之间最长的简单路径即为树的直径，
//f[i]: 以i为起点的最长链
// 直径 =max(包含i的最长路径）= max(i的子树最长链 + i的子树次长链 + 1） 

//深搜求树的直径 
void dfs(int u, int father) {
	int m1=0, m2=0; //子树最长链，子树次长链 
	for(int v:e[u]) {
		if(v != father) { //无根树添加判断 
			dfs(v, u); //基于v点做深搜 
			if(f[v] > m1) { //当f[v]的长度比子树最长链m1长 
				m2= m1; //更新次长链 
				m1= f[v]; //更新最长链 
			} else if(f[v] > m2){
				m2 = f[v]; //更新次长链 
			}
		}
	}
	f[u] = m1+1; //更新以u为起点的最长链：子树最长链+1 
	ans = max(ans, m1+m2+1); // 经过u点的最长链 
}

