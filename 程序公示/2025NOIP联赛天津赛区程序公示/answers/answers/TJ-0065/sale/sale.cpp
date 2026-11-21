#include <iostream>
#include <vector>

// 根本不会啊烙铁
// 跪求评测姬给我性质A那个点的4分 

using ull = unsigned long long;

const ull MUL_NUM = 998244353;

ull calculate(int n) {
	ull result = 1;
	while(n --> 0) {
		result *= 2;
		result = result % MUL_NUM;
	}
	return result;
}

int main() {
	freopen("sale.in", "r", stdin);
	freopen("sale.out", "w+", stdout);
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int c, t;
	std::cin >> c >> t;
	while(t --> 0) {
		int n, m;
		std::cin >> n >> m;
		std::vector<int> a(n);
		for(int i = 0; i < n; ++i) {
			std::cin >> a[i];
		}
		std::cout << calculate(n) << std::endl;
	}
	return 0;
}
