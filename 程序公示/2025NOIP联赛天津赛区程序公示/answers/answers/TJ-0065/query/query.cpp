#include <iostream>

int main() {
	// 读写加速&文件读写 
	FILE *ifp = freopen("query.in", "r", stdin);
	FILE *ofp = freopen("query.out", "w+", stdout);
	std::cout << ifp << ' ' << ofp << std::endl; // 随机数这一块:/ 
	fclose(ifp);
	fclose(ofp);
	return 0;
}

