#include <iostream>
#include <vector>
#include <cstdio>
#include <limits>
using namespace std;
int n;
vector<int64_t> nums;
/*void push_up(int i) {
	tree[i] = tree[i * 2] + tree[i * 2 + 1];
	return;
}
void build(int i, int left, int right) {
	if (left == right) {
		tree[i] = nums[left];
		return;
	}
	int mid = (left + right) / 2;
	build(i * 2, left, mid);
	build(i * 2 + 1, mid + 1, right);
	push_up(i);
	return;
}*/
vector<int64_t> pre;
int main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	nums.assign(n + 1, 0);
	pre.assign(n + 1, 0);
	for (int i = 1; i <= n; i++) {
		cin >> nums[i];
		//cout << i  << " " << nums[i] << endl;
		pre[i] = pre[i - 1] + nums[i];
		//cout << nums[i] << " " << i << endl;
	}
	int q;
	cin >> q;
	//cout << n << endl;
	int64_t ans = 0;
	for (int i = 0; i < q; i++) {
		int ql, qr;
		cin >> ql >> qr;
		vector<int64_t> k(n + 1, -numeric_limits<int64_t>::max());
		for (int l = ql; l <= qr; l++) {
			for (int j = 1; j <= n; j++) {
				for (int begin = i - l + 1; begin <= j; begin++) {
					if (begin < 1) continue;
					if (begin + l - 1 > n) break;
					k[j] = max(k[j], pre[begin + l - 1] - pre[begin - 1]);
				}
			}
		}
		for (int j = 1; j <= n; j++) {
			ans = ans ^ ((j * k[j] % (__int128_t(1) << 64)));
		}
		cout << k[1] << " " << k[2] << " " << k[3] << " " << k[4] << endl;
	}
	return 0;
}
