#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
	long long x, y;
};
node a[100010];
bool cmp(node t1, node t2)
{
	return t1.x < t2.x;
}
int main()
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	long long mins = 1e18;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x >> a[i].y;
		mins = min(mins, a[i].x + a[i].y);
	}
	sort(a + 1, a + n + 1, cmp);
	long long ans = 0;
	long long sum = 0;
	for (int i = 0; i <= n; i++)
	{
		sum += a[i].x;
		if (sum > m) break;
		ans = max(ans, (m - sum) / mins * 2 + i);
	}
	cout << ans;
	return 0;
}
