#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL qpow(LL a, LL b, LL m)
{
	LL ans = 1;
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			ans = ans * a % m;
		}
		b /= 2;
		a = a * a % m;
	}
	return ans;
}
int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << qpow(a, b, c);
}
