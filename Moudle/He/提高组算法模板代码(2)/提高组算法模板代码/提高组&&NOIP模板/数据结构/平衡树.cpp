//平衡树：平衡的二叉搜索树，可以将树的高度控制在logn的级别，防止退化成链
// Treap：结合二叉搜索树和堆的性质，每个节点维护两个值，节点值满足BST树性质，
//随机生成优先级的值，维护堆的性质
// 无旋Treap（FHQ Treap): 使用分裂和合并两个操作维护树的平衡

//STL 类： set使用红黑树实现，也是平衡树，可以实现数据快速插入，删除和查找 

struct Node{
	int l, r;//左右子树 
	int val; //树的权值 
	int rnd; //堆的随机值 
	int size;//树大小 
};

int n, root, idx;  
Node tr[100005];

//子树值更新父节点的值 
void pushup(int p){
	tr[p].size = tr[tr[p].l].size +  tr[tr[p].r].size + 1;
}

//创建新节点 
void newNode(int &x, int v) {
	x = ++idx; // 动态开店 
	tr[x].val = v; //设置点值 
	tr[x].rnd = rand(); //生成随机值 
	tr[x].size = 1; //设置树的大小 
}

//树的分裂：将树p，根据v的值分裂成两棵树
//第一棵树中所有点的值都<=v, 根节点用x保存
//第二棵树中所有点的值都>v, 根节点用y保存 
void split(int p, int v, int &x, int &y) {
	if(!p) { //当前没有节点 
		x = y = 0; //两棵树的根节点设置为0 
		return; 
	}
	
	//当前点的val值<=v，则当前点和其左子树作为第一棵树，且当前点是第一个棵树的根 
	if(tr[p].val <= v) {  
		x = p; //设置p为第一棵树的根，赋值给x 
		split(tr[p].r, v, tr[x].r, y); //拆分p的右子树，右子树中<=v 的作为第一棵树的右子树 
		pushup(x); //更新树x 
	} else {
		y = p; //当前值>v,则当前值和右子树作为第二棵树，当前点是第二棵树的根 
		split(tr[p].l, v, x, tr[y].l); //拆分左子树，左子树中>v的部分，作为第二棵树的左子树 
		pushup(y); //更新树y 
	}
}

//树合并：将根节点为x，y的两个节点进行合并，返回合并后的根节点 
//要求x中所有节点的值 <= y中所有节点的值 
int merge(int x, int y) {
	if(!x || !y) { //任意一棵树为空 
		return x+y; //返回另一个树 
	}
	
	//根据随机生成的值判断哪棵树是根，实现堆的性质（小顶堆） 
	if(tr[x].rnd < tr[y].rnd) { //x的优先级<y的优先级，x为根 
		tr[x].r = merge(tr[x].r, y); //x的右子树和y进行合并，更新为x的右子树 
		pushup(x); //更新x 
		return x; //返回根节点 
	} else { // y的优先级<x的优先级，y为根 
		tr[y].l = merge(x, tr[y].l); //y的左子树和x进行合并，更新为y的左子树 
		pushup(y); //更新y 
		return y; //返回根节点 
	}
} 

//插入新结点 
void insert(int v) {
	int x, y, z;
	split(root, v, x, y); //将树按v分裂成两棵树x, y 
	newNode(z, v); //根据v点创建一棵独根树 
	root = merge(merge(x, z), y); //合并x,z,y ,并重新设置根节点 
} 

//删除新节点 
void del(int v) {
	int x, y, z;
	split(root, v, x, z); //将树按v分裂成两个数x, z 
	split(x, v-1, x, y); //将树x按v-1分裂成两棵树x, y 
	y = merge(tr[y].l, tr[y].r); //将树y删除掉根节点，也就是合并树的两棵子树 
	root = merge(merge(x, y), z);  //合并树 x, y, z, 并更新根节点 
}

//返回 值v的排名 
int getrank(int v) {
	int x, y;
	split(root, v-1, x, y); //将树按v-1分裂成两棵树x, y 
	int ans = tr[x].size + 1; //树x的节点个数+1 就是v的排名 
	root = merge(x, y); //合并树x ,y 
	return ans;
}

//返回 排名v的值 
int getval(int p, int v) {
	if(!p) { //如果树为空 
		return 0;
	} 
	if(tr[tr[p].l].size + 1 == v ) { //如果左子树大小+1 ==v 
		return tr[p].val;  //当前节点就是排名v的节点，直接返回 
	} else if(v <= tr[tr[p].l].size) { //如果左子树的大小>=v, 则v在左子树 
		return getval(tr[p].l, v); //查询左子树 
	} else {
		return getval(tr[p].r, v-tr[tr[p].l].size-1); //v在右子树，查询剩余排名 
	}
}

//返回前驱：小于v 的最大值 
int getpre(int v) {
	int x, y;
	split(root, v-1, x, y); //将树按v-1分裂成两棵树x,y 
	int ans = getval(x, tr[x].size); //x中最大值就是前驱，也就是在树x中查询最后一名的值 
	root = merge(x, y); //合并x,y 
	return ans;
} 

//返回后继: >v 的最小值 
int getnx(int v) {
	int x, y;
	split(root, v, x, y); //将树按v分裂成两棵树x, y 
	int ans = getval(y, 1); //树y中的最小值就是后继，也就是在y中查询第一名的值 
	root = merge(x,y); //合并 x,y
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	//如果不确保有前驱和后继，需要添加哨兵
//	insert(-inf);
//	insert(inf); 
	
	cin>>n;
	for(int i=1; i<=n; i++) {
		int opt, x;
		cin>>opt>>x;
		if(opt == 1) {
			insert(x); //插入 
		} 
		if(opt == 2) {
			del(x); //删除 
		}
		if(opt == 3) {
			cout<<getrank(x)<<'\n';  //获得x的排名 
		}
		if(opt == 4) {
			cout<<getval(root, x)<<'\n'; //获得排名x的值 
		}
		if(opt == 5) {
			int pre = getpre(x); //获得前驱 
			cout<<pre<<'\n';
		}
		if(opt == 6) {
			int nx = getnx(x); //获得后继 
			cout<<nx<<'\n'; 
		}
	}
	
	return 0;
} 
 
