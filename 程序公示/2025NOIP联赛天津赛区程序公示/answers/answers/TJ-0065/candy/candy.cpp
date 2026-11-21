#include <iostream>
#include <queue>
#include <climits>

// 分析一手
// 看到这道题第一眼直接就是完全背包
// 但是往下一看数据，m<=1e18
// 证明完全背包一定不行，因为dp时间复杂度一定至少为O(n)，但是这个数据连O(n)都过不了
// 另辟蹊径使用优先队列+贪心，注意需要先把first们算上，然后直接除
// 时间复杂度可以直接简化为O(1)左右（其实不是O(1)但是很够用了，至少循环体部分和m没关系所以应该能过） 
// p.s. 蒟蒻to写个O(1)还得加cout调试(逃)，代码实在太烂惹
// 我也不知道这个代码有木有问题，应该没有吧(祈祷ing 
// 反正7个数据点过了
// TLE MLE RE肯定不会有
// ccf补药卡我代码 

using ull = unsigned long long;

std::pair<ull, ull> get_min(const std::pair<ull, ull> &a, const std::pair<ull, ull> &b) {
	if(a.first + a.second < b.first + b.second) {
		return a;
	}
	return b;
}

ull sum(const std::pair<ull, ull> &pair) {
	return pair.first + pair.second;
}

int main() {
	// 读写加速&文件读写 
	FILE *ifp = freopen("candy.in", "r", stdin);
	FILE *ofp = freopen("candy.out", "w+", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	ull n, m;
	std::cin >> n >> m;
	std::priority_queue<ull, std::vector<ull>, std::greater<int>> first_queue; // 优先队列，存储所有的x
	std::pair<ull, ull> min_pair = std::make_pair(INT_MAX, INT_MAX); // 最小的xy和
	for(ull i = 0, x, y; i < n; std::cin >> x >> y, min_pair = get_min(min_pair, std::make_pair(x, y)), first_queue.push(x), ++i);
	ull result = 0;
	bool flag = false;
	ull current_top = first_queue.top();
	while(current_top + first_queue.top() < sum(min_pair) && first_queue.top() < std::max(min_pair.first, min_pair.second)) {
		// 不能让它把我们后面要处理的min_pair状态变了 
		if(!flag && first_queue.top() == min_pair.first) {
			flag = true;
			current_top = first_queue.top();
			first_queue.pop();
			continue;
		}
//		std::cout << "Added: " << first_queue.top() << std::endl;
		m -= first_queue.top();
		current_top = first_queue.top();
		first_queue.pop();
		++result;
		if(current_top + first_queue.top() > sum(min_pair) && !flag && first_queue.top() != min_pair.first) { // 返还可能导致多花钱的结果
//			std::cout << "Back: " << current_top << ", " << first_queue.top() << std::endl;
			m += first_queue.top();
			--result;
		}
//		std::cout << "Now top:" << first_queue.top() << std::endl;
	}
//	std::cout << "Last: " << first_queue.top() << std::endl;
//	std::cout << min_pair.first << ' ' << min_pair.second << std::endl;
//	std::cout << result << ", " << m << std::endl;
	result += (m / sum(min_pair)) * 2ull; // 计算可知在xy和这一对能买多少颗糖
	if(m % sum(min_pair) > min_pair.first) {
		++result;
	}
	std::cout << result << std::endl;
	fclose(ifp);
	fclose(ofp);
	return 0;
}

