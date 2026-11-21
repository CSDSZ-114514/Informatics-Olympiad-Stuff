#include <iostream>
using namespace std;
int a[50010];
int main()
{
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++)
	{
		int l, r;
		cin >> l >> r;
	}
	return 0;
}
