#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
using namespace std;
struct Node {
	vector<int64_t> pri;
	int64_t num;
	Node(): pri(vector<int64_t>(2, 0)), num(0) {}
};
int n;
int64_t m;
vector<Node> candy;
int64_t backtrack(int64_t m, string& p) {
	if (m == 0) {
		return 0;
	}
	return 0;
}
void solve1() {
	int64_t min_p = 1e9 + 1;
	for (int i = 1; i <= n; i++) {
		min_p = min(min_p, candy[i].pri[0]);
	}
	cout << int(double(m) / double(min_p)) << endl;
	return;
}
void solve2() {
	int64_t sum = 2 * 1e9 + 1;
	for (int i = 1; i <= n; i++) {
		sum = min(sum, candy[i].pri[0] + candy[i].pri[1]);
	}
	cout << int(m / sum * 2) << endl;
	return;
}
bool compare(pair<int, int64_t> a, pair<int, int64_t> b) {
	return a.second < b.second;
}
void solve3() {
	vector<pair<int, int64_t>> aver(n + 1, make_pair(0, 0));
	vector<pair<int, int64_t>> first(n + 1, make_pair(0, 0));
	vector<pair<int, int64_t>> second;
	for (int i = 1; i <= n; i++) {
		aver[i].first = i;
		aver[i].second = candy[i].pri[0] + candy[i].pri[1];
		first[i].first = i;
		first[i].second = candy[i].pri[0];
	}
	sort(aver.begin() + 1, aver.end(), compare);
	sort(first.begin() + 1, first.end(), compare);
	int64_t ans = 0;
	for (int i = 1; i <= n; i++) {
		if (first[i].second <= aver[1].second / 2 && m >= first[i].second) {
			ans++;
			m -= first[i].second;
			if (candy[first[i].first].pri[1] <= aver[1].second / 2) {
				ans++;
				m -= candy[first[i].first].pri[1];
			}
			else {
				second.push_back(make_pair(first[i].first, candy[first[i].first].pri[1]));
			}
		}
		else {
			second.push_back(first[i]);
		}
	}
	ans += int(m / aver[1].second * 2);
	sort(second.begin(), second.end(), compare);
	m -= m / aver[1].second * aver[1].second;
	for (int i = 0; i < int(second.size()); i++) {
			if (m >= second[i].second) {
				m -= second[i].second;
				ans++;
			}
		}
	cout << ans << endl; 
	return;
}
int main() {
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	candy.assign(n + 1, Node());
	bool speA = true;
	bool speB = true;
	for (int i = 1; i <= n; i++) {
		cin >> candy[i].pri[0] >> candy[i].pri[1];
		if (candy[i].pri[0] != candy[i].pri[1]) {
			speA = false;
		}
		if (candy[i].pri[0] < candy[i].pri[1]) {
			speB = false;
		}
	}
	if (speA) {
		solve1();
	}
	else if (speB) {
		solve2();
	}
	else {
		solve3();
	}
	return 0;
}
