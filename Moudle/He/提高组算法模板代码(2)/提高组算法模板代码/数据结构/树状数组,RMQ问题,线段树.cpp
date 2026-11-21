//树状数组： 用于数组中的元素不断地被修改，然后查询任意区间所有元素之和。
//查询和修改时间复杂度都为log(n) 。
//维护差分数组sum[]

//返回x的二进制中最后一个1和后面的0的结果 
int lowbit(int x) {
	return x & -x;
}
//x的值增加k 
void change(int x, int k) {
	while(x<=n) {
		sum[x]+=1;
		x+=lowbit(x);
	}
}
//查询前x个元素的和 
int query(int x) {
	int s = 0;
	while(x) {
		s += sum[x];
		x-=lowbit(x);
	}
	return s;
}

———————————————————————————————————————— 
//倍增法解决RMQ 问题
//倍增法：只枚举2的整数次幂上的值 
//RMQ问题：求区间最值问题，两个小区间的最值组合大区间的最值 
//f[i][j]: 以i为起点，长度为2^j区间的最值 
int main() {	
	//预处理数组f[i][j] 
	for(int j=1; j<=log2(n); j++) { //枚举区间长度 
		for(int i=1; i+(1<<j)-1<=n; i++) { //枚举起点 
			f[i][j] = max(f[i][j-1], f[i+(1<<(j-1))][j-1]); //两个区间的最值 
		}
	}
	
	//查询[L, R] 区间最值 
	int k = log2(R-L+1);
	cout<<max(f[L][k], f[R-(1<<k)+1][k]) //拆成两个区间求最值 
} 

————————————————————————————————————————
//线段树：维护区间信息，在O(logn)的时间复杂度内实现单点修改、区间修改、区间查询等操作
struct Node{
	long long L, R;
	long long sum, add; // sum, 区间和， add:懒惰标记，当有区间修改时 
};
//创建线段树，维护区间和 
void build(int p, int L, int R) {
	tr[p] = {L, R, 0}; //创建当前节点 
	if(L==R) { //叶子节点时递归结束 
		tr[p].sum = a[L]; 
		return;
	}
	int mid=(L+R)/2; //将区间一分为二 
	build(2*p, L, mid); //创建左子树 
	build(2*p+1, mid+1, R); //创建右子树 
}

//单点修改x，增加k 
void update(int p, int x, int k) {
	if(tr[p].L == tr[p].R) { //更新到叶子节点，递归结束 
		tr[p].sum += k;
		return;
	}
	int mid = (tr[p].L + tr[p].R)/2; // 
	if(x<=mid) { //如果x在左区间 
		update(2*p, x, k); //更新左子树 
	} else {
		update(2*p+1, x, k); //更新右子树 
	}
	tr[p].sum = tr[2*p].sum + tr[2*p+1].sum; //回溯更新根节点的统计值 
}

//当有懒惰标记时，更新查询节点的子树时，需要做pushdown处理，保证子 
void pushdown(int p) {
	if(tr[p].add) {
		tr[2*p].sum += (tr[2*p].R-tr[2*p].L+1)*tr[p].add; //更新左子树统计值
		tr[2*p].add += tr[p].add; //更新左子树懒惰标记 
		tr[2*p+1].sum += (tr[2*p+1].R-tr[2*p+1].L+1)*tr[p].add;//更新右子树统计值
		tr[2*p+1].add += tr[p].add;//更新右子树懒惰标记 
		tr[p].add = 0; //更新当前节点懒惰标记为0 
	}
}

//区间修改，区间[x,y] 所有元素加k 
void update(int p, int x, int y, int k) {
	if(x <=tr[p].L && tr[p].R<=y) { //当前节点所有元素都在待更新区间，递归结束 
		tr[p].sum += (tr[p].R - tr[p].L +1)*k; //更新当前节点的区间和 
		tr[p].add +=k; //更新懒惰标记 
		return; 
	}
	pushdown(p); //含有懒惰标记时，先将子树统计值更新正确，在处理子树 
	int mid = (tr[p].L + tr[p].R)/2;
	if(x<=mid) { //左子树有元素在更新区间 
		update(2*p, x, y, k); //更新左子树 
	}
	if(y>mid) { //右子树有元素在更新区间 
		update(2*p+1, x, y, k); //更新右子树 
	}
	tr[p].sum = tr[2*p].sum + tr[2*p+1].sum; //回溯更新根节点的统计值 
}

//区间查询，查询区间[x,y]的区间和 
long long query(int p, int x, int y) {
	if(x<=tr[p].L && tr[p].R<=y) { //当前节点所有元素都在待更新区间，递归结束 
		return tr[p].sum; //返回当前节点的统计值 
	}
	pushdown(p); //含有懒惰标记时，先将子树统计值更新正确，在处理子树 
	int mid = (tr[p].L + tr[p].R)/2;
	long long sum = 0;
	if(x<=mid) { //左子树有元素在查询区间 
		sum += query(2*p, x, y); //查询左子树 
	}
	if(y>mid) { //右子树有元素在查询区间 
		sum += query(2*p+1, x, y); //查询右子树 
	}
	return sum;
}


