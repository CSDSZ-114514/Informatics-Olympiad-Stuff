//线段树：基于分治思想的二叉树，用来维护区间信息（区间和，区间最值，区间GCD等）
//可以在O(logn)的时间复杂度内实现单点修改，区间修改，区间查询等操作。
//线段树叶子节点存储元素本身，非叶子节点存储区间元素的统计值。

struct Node{
	long long L, R, sum, add;
};

Node tr[400005]; //线段树数组 长度:4*n 

//子结点的值更新父节点 
void pushup(int p) {
    tr[p].sum = tr[2*p].sum + tr[2*p+1].sum;
}

//具有懒惰标记的线段树，父节点的值更新子结点的值 
void pushdown(int p) {
	if(tr[p].add) { //父节点的懒惰标记不为0，代表父节点的处理未更新到子结点 
		tr[2*p].sum += (tr[2*p].R - tr[2*p].L+1)*tr[p].add; //更新子结点的统计值 
		tr[2*p].add += tr[p].add; //更新子结点的懒惰标记 
		tr[2*p+1].sum += (tr[2*p+1].R - tr[2*p+1].L+1)*tr[p].add;
		tr[2*p+1].add += tr[p].add;
		tr[p].add = 0; //父节点的懒惰标记清空 
	}
}

//创建线段树，p：当前节点编号， L，R：节点对应的区间 
void build(int p, int L, int R) {
	tr[p] = {L, R, 0}; //创建当前节点 
	
	if(L==R) { // 如果是叶子节点 
		tr[p].sum = a[L]; //更新统计值
		return; 
	} 
	
	int mid = (L+R)/2;
	build(2*p, L, mid); //在区间[L,mid] 创建左子树 
	build(2*p+1, mid+1, R); //在区间[mid+1,R] 创建右子树 
	pushup(p); //子树的结果更新当前节点 
}
//单点更新：将点x的值增加k 
void update(int p, int x, int k) {
	if(tr[p].L == tr[p].R ) { //如果是叶子节点 
		tr[p].sum += k; //更新当前节点 
		return; 
	} 
	pushdown(p); //如果存在懒惰标记更新子树 
	int mid = (tr[p].L + tr[p].R)/2;
	if(x <= mid) { //如果x在左子树
		update(2*p, x, k); //更新左子树 
	} else{
		update(2*p+1, x,k); //更新右子树 
	}
	pushup(p); //左右子树更新当前节点 

}

//区间更新：在区间[x,y]内所有节点增加k 
void update(int p, int x, int y, int k) {
	if(x <= tr[p].L && tr[p].R <= y) { //如果当前节点区间都在区间[x,y] 内 
		tr[p].sum += (tr[p].R - tr[p].L+1)*k; //更新区间统计值 
		tr[p].add += k; //更新当前节点懒惰标记
		return; 
	} 
	pushdown(p); //更新子树 
	int mid = (tr[p].L + tr[p].R)/2;
	if(x <= mid) { //如果左子树在范围[x,y]内 
		update(2*p, x, y, k); //更新左子树 
	}
	if(y>mid) { //如果右子树在范围[x,y]内 
		update(2*p+1, x, y, k); //更新右子树 
	}
	pushup(p); //左右子树更新当前节点 

}

//单点查询
long long query(int p, int x) {
	if(tr[p].L == tr[p].R) {
		return tr[p].sum;
	}
	pushdown(p); //如果存在懒惰标记更新子树 
	int mid = (tr[p].L + tr[p].R)/2;
	if(x<=mid) {
		return query(2*p, x);
	} else {
		return query(2*p+1, x);
	}
} 

//查询区间[x,y] 
long long query(int p, int x, int y) {
	if(x<=tr[p].L && tr[p].R<=y) {//如果当前节点区间都在区间[x,y] 内 
		return tr[p].sum; //返回当前区间的值 
	}
	
	pushdown(p); //更新子树 
	int mid = (tr[p].L + tr[p].R)/2;
	long long sum = 0;
	if(x<=mid) { //如果左子树在范围[x,y]内 
		sum += query(2*p, x, y);  //累计左子树的值 
	}
	if(y>mid) {//如果右子树在范围[x,y]内 
		sum += query(2*p+1, x, y); //累计右子树的值 
	}
	
	return sum; //返回结果 

} 
