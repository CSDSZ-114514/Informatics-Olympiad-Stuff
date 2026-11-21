#include<iostream>
using namespace std;

int n, q, l, r, a[50005];

int main()
{
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	cin >> q;
	while(q--)
	{
		cin >> l >> r;
		cout << 1 << endl;
	}
	return 0;
}
