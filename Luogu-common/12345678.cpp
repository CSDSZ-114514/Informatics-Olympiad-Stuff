#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

long long solve1(int n) {
	vector<bool> p(n + 1, true);
	vector<long long> f(n + 1, 0), g(n + 1, 0);
	f[1] = 1;
	for (int i = 2; i * i <= n; i++) {
		if (p[i]) {
			vector<int> d;
			for (int k = i; k <= n; k *= i) d.push_back(k);
			reverse(d.begin(), d.end());
			for (int k : d) {
				for (int j = k; j <= n; j += k) {
					if (p[j]) {
						p[j] = false;
						f[j] = i;
						g[j] = k;
					}
				}
			}
		}
	}
	for (int i = sqrt(n) + 1; i <= n; i++) {
		if (p[i]) {
			f[i] = i;
			g[i] = i;
		}
	}
	long long sum = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i / g[i]] * (g[i] * f[i] - 1) / (f[i] - 1);
		sum += f[i];
	}
	return sum;
}

long long solve2(int n) {
	long long sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += i * (n / i);
	}
	return sum;
}

int main() {
	int n;
	cin >> n;
	cout << solve1(n) << endl;
	cout << solve2(n) << endl;
	return 0;
}
