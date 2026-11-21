//扫描线：用来解决几何图形的面积交并，周长交并问题。
//核心是利用扫描线（通常是水平线或垂直线）在几何空间中扫描对象，以确定哪些对象与扫描线相交。

//扫描线处理面积交并问题
//1. 扫描线从下往上扫描，每一个矩形的上下边为界，n个矩形有2n个扫描线，分成2n-1个区块
//2. 每一个区块的高 = 相邻扫描线的y坐标之差
//3. 扫描线覆盖x坐标的总长度，用线段树处理：对于每一个矩形的入边，增加矩形长度的贡献
//   对于矩形的出边，减少矩形长度的贡献
//4. 每个区块的面积= x轴覆盖总长度 * 高度
//5. x坐标需要用权值线段树维护，坐标范围大，需要离散化， 
//   离散化后为了区间连贯，更新传参时，右端点向左偏一，计算时，右端点向右偏一

//线段树结构体 
struct Tree{
	ll L, R, cnt, len; //cnt:当前区间全覆盖次数， len：当前区间覆盖长度 
}; 

Tree tr[8*N]; //数组大小设置成8n 

//扫描线结构体 
struct Node{
	ll x1, x2, y, tag; //x1,x2:存储x坐标  y：存储y坐标，tag存储入边1出边-1 
}; 

Node a[N]; 
ll n, b[N], ans; //b[]:用于x坐标离散化 

//更新p节点的覆盖长度len 
void pushup(ll p) {
	if(tr[p].cnt) {//当前区间全覆盖 
		tr[p].len = b[tr[p].R + 1] - b[tr[p].L]; //直接计算坐标范围，右端点右移一下 
	} else {
		tr[p].len = tr[2*p].len + tr[2*p+1].len; //通过子结点得覆盖范围计算 
	}
}

//创建权值线段树 
void build(ll p, ll L, ll R) {
	tr[p] = {L, R, 0, 0};
	
	if(L==R) {
		return;
	}
	ll mid = (L+R)/2;
	build(2*p, L, mid);
	build(2*p+1, mid+1, R);
	pushup(p);
}

//更新区间[x, y] 的覆盖次数 +k 
void update(ll p, ll x, ll y, ll k) {
	//当区间全覆盖，直接更新 
	if(x<=tr[p].L && tr[p].R<=y) {
		tr[p].cnt += k; //覆盖次数累积 
		pushup(p); //更新区间覆盖长度 
		return;
	}
	//因为没有区间查询，且更新的只是覆盖次数，所以不需要创建懒惰标记并下移 
	ll mid = (tr[p].L + tr[p].R)/2;
	if(x<=mid) { //更新左子树 
		update(2*p, x, y, k);
	}
	if(y > mid) { //更新右子树 
		update(2*p+1, x, y, k);
	}
	pushup(p); //更新当前节点的覆盖长度 
}

//扫描线按y坐标从小到大处理 
bool cmp(Node a, Node b) {
	return a.y < b.y;
}

int main() {
	cin>>n;
	for(ll i=1; i<=n; i++) {
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		a[2*i-1] = {x1, x2, y1, 1}; //保存入边扫描线 
		a[2*i] = {x1, x2, y2, -1}; //保存出边扫描线 
		b[2*i-1] = x1; //保存x坐标，用于离散化 
		b[2*i] = x2;
	}
	n*=2;  
	sort(a+1, a+n+1, cmp); //扫描线按y坐标从小到大排序 
	sort(b+1, b+n+1); //x坐标数组排序 
	ll len = unique(b+1, b+n+1) - (b+1); //x坐标去重，用于离散化 
	build(1, 1, len-1); //创建线段树 
	
	//依次处理每个扫描线 
	for(ll i=1; i<n; i++) {
		ll l = lower_bound(b+1, b+len+1, a[i].x1) - b; //获取离散化后的x坐标范围 
		ll r = lower_bound(b+1, b+len+1, a[i].x2) - b;
		update(1, l, r-1, a[i].tag); //根据入边+，出边减，更新区间，右区间左移 
		ans += tr[1].len * (a[i+1].y - a[i].y); //根节点覆盖范围为长 * (y坐标之差） 
	}

	cout<<ans;

	return 0;
} 

//扫描线处理周长交并问题
// 1. 计算横边
//    扫描线从下往上处理，当前扫描线贡献的横边长度 = abs（当前覆盖长度- 上次覆盖长度）
//    所有扫描线贡献长度之和 + 最上面扫描线的x区间的长度 = 总横边长度
// 2. 计算竖边
//    竖边的长度 = 相邻扫描线y坐标之差，
//    当前扫描线贡献竖边长度 = 竖边个数 * 竖边长度
//    竖边个数在线段树中维护，添加竖边个数，已经左右两个端点是否被覆盖

//线段树结构体 
struct Tree{
	ll L, R, cnt, len; //cnt:当前区间全覆盖次数， len：当前区间覆盖长度 
	ll sum; //存储区间内有几条竖边
	bool lcover, rcover; //区间左右边是否被覆盖 
}; 

const int N = 100005; 
Tree tr[8*N]; //数组大小设置成8n 

struct Node{
	ll x1, x2, y, tag; //x1,x2:存储x坐标  y：存储y坐标，tag存储入边1出边-1 
}; 

Node a[N]; 
ll n, b[N], ans; //b[]:用于x坐标离散化 

void pushup(ll p) {
	//当前区间全覆盖 
	if(tr[p].cnt) {
		tr[p].len = b[tr[p].R + 1] - b[tr[p].L]; //如果被覆盖，直接计算坐标范围
		tr[p].sum = 2; //竖边个数为左右两条边 
		tr[p].lcover = tr[p].rcover = 1;  //左右两个端点都被覆盖 
	} else {
		tr[p].len = tr[2*p].len + tr[2*p+1].len; //通过子结点得覆盖范围计算
		tr[p].sum = tr[2*p].sum + tr[2*p+1].sum; //更新竖边条数 
		tr[p].lcover = tr[2*p].lcover; //更新区间左右两边得覆盖情况 
		tr[p].rcover = tr[2*p+1].rcover;
		//如果中间两个端点均被覆盖，竖边条数合并时减2 
		if(tr[2*p].rcover && tr[2*p+1].lcover) {
			tr[p].sum -= 2; //区间连接处重合，少两条边 
		}
	}
}

//创建权值线段树 
void build(ll p, ll L, ll R) {
	tr[p] = {L, R, 0, 0};
	
	if(L==R) {
		return;
	}
	ll mid = (L+R)/2;
	build(2*p, L, mid);
	build(2*p+1, mid+1, R);
	pushup(p);
}

//更新区间[x, y] 覆盖次数 
void update(ll p, ll x, ll y, ll k) {
	if(x<=tr[p].L && tr[p].R<=y) {
		tr[p].cnt += k;
		pushup(p);
		return;
	}
	ll mid = (tr[p].L + tr[p].R)/2;
	if(x<=mid) {
		update(2*p, x, y, k);
	}
	if(y > mid) {
		update(2*p+1, x, y, k);
	}
	pushup(p);
}

//为了保证两个矩形相切时处理正确（跟两矩形相交时相同），按双关键字排序
//先按y坐标从小到大，如果y坐标相同，先处理入边在处理出边 
bool cmp(Node a, Node b) {
	if(a.y != b.y) {
		return a.y < b.y; //先处理y坐标 
	} else {
		return a.tag > b.tag; //y坐标相等时，先处理入边，在处理出边 
	}
}

int main() {
	cin>>n;
	for(ll i=1; i<=n; i++) {
		ll x1,x2,y1,y2;
		cin>>x1>>y1>>x2>>y2;
		a[2*i-1] = {x1, x2, y1, 1}; //保存入边 
		a[2*i] = {x1, x2, y2, -1}; //保存出边 
		b[2*i-1] = x1;
		b[2*i] = x2;
	}
	n*=2;
	sort(a+1, a+n+1, cmp);
	sort(b+1, b+n+1);
	ll len = unique(b+1, b+n+1) - (b+1); //x坐标离散化 
	build(1, 1, len-1); //创建线段树 
	
	ll last = 0;
	for(ll i=1; i<n; i++) {
		ll l = lower_bound(b+1, b+len+1, a[i].x1) - b;
		ll r = lower_bound(b+1, b+len+1, a[i].x2) - b;
		update(1, l, r-1, a[i].tag); //更新区间覆盖次数，更新时右区间左移 
		ans += abs(tr[1].len-last); //当前扫描线贡献横边长度=根节点覆盖范围-上一条扫描边覆盖范围
		last = tr[1].len; //更新上一次覆盖范围变量 
		ans += tr[1].sum * (a[i+1].y-a[i].y); //统计当前扫描线贡献竖边长度 
	}
	
	ans += a[n].x2 - a[n].x1; //加上最后一条扫描线得长度 
	cout<<ans;

	return 0;
} 




