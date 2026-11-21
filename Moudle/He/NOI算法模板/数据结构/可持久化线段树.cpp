//可持久化线段树：一种支持查询和修改历史版本的线段树结构，通过复用未修改节点实现
//高效的空间利用，常用于历史状态回溯或解决区间查询问题

//如果题目给的空间比较小，且不需要维护整颗线段树的信息，
//每次修改只会修改一个位置的值，可以不事先创建线段树，只在更新的时候直接更新
//这时需要把把区间[L, R] 作为参数，不能从节点获得 

//主席树：可持久化权值线段树，线段树范围是值域范围，维护数出现的次数
//主要用于解决区间第k小值查询问题 

struct Node{
	int L, R, val; //L,R 维护节点区间， val维护节点值 
	int ls, rs; //保存左右子树节点编号 
};

Node tr[N*25]; //线段树大小n(logn+3) 

int n, m, tot, root[N], a[N]; //root[]：维护历史版本根节点编号 

//创建线段树，并返回根节点编号p 
void build(int &p, int L, int R) {
	p = ++tot; //动态开点 
	tr[p] = {L, R, 0, 0, 0}; //创建新节点 
	
	if(L==R) { //如果是叶子节点 
		tr[p].val = a[L]; //更新节点值 
		return;
	}
	
	int mid = (L + R)/2;
	build(tr[p].ls, L, mid); //创建左子树，并保存左子树编号 
	build(tr[p].rs, mid+1, R); //创建右子树，并保存右子树编号 
}

//基于旧版本根节点编号v，创建新版本根节点编号p，将x的值更新为k 
//p:当前处理的节点，v：旧版本编号 
//如果不初始化创建线段树，则更新时需要提供区间
// void update(int &p, int v, int L, int R, int x, int k)
 
void update(int &p, int v, int x, int k) {
	p = ++tot; //动态创建新点 
	tr[p] = tr[v]; //复制旧版本信息 
	
	if(tr[p].L==tr[p].R) { //如果是叶子节点 
		tr[p].val = k; //更新，返回 
		return;
	}
	
	int mid = (tr[p].L+ tr[p].R)/2;
	if(x<=mid) { //节点属于左子树 
		update(tr[p].ls, tr[v].ls, x, k); //更新左子树，并更新左子树编号 
	} else {
		update(tr[p].rs, tr[v].rs, x, k);//更新右子树，并更新右子树编号 
	}
}

//查询x的值 
int query(int p, int x) {
	if(tr[p].L== tr[p].R) { //如果是叶子节点直接返回 
		return tr[p].val;
	}
	
	int mid = (tr[p].L+ tr[p].R)/2;
	if(x<=mid) { //x属于左子树 
		return query(tr[p].ls, x); //查询左子树 
	} else {
		return query(tr[p].rs, x); //查询右子树 
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	 
	cin>>n>>m;
	
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	
	build(root[0], 1, n); //初始化线段树，作为版本0 
	
	for(int i=1; i<=m; i++) {
		int v, op, x, k;
		cin>>v>>op;
		
		if(op==1) {
			cin>>x>>k;
			
			update(root[i], root[v], x, k); //基于版本v，创建当前版本 
		} else {
			cin>>x;
			root[i] = root[v]; //复制旧版本 
			cout<<query(root[v], x)<<'\n';
		}
	}

	return 0;
} 
 
