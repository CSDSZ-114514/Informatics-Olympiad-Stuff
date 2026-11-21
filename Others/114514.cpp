#include <iostream>
using namespace std;

long long dict[1000010], ad[1000010];

int main()
{
	string s;
	cin >> s;
	int cur = 0, len = s.size();
	for (int i = 1; i <= len; i++)
	{
		dict[i] = dict[i - 1];
		if (s[i - 1] == 'I')
		{
			dict[i]++;
		}
		if (s[i - 1] == 'O')
		{
			cur++;
			ad[cur] = i;
		}
		
	}
	long long sum = 0;
	for (int i = 1; i <= cur; i++)
	{
// cout << ad[i] << endl << dict[ad[cur] - 1] << ' ' << (dict[len] - dict[ad[i]]) << endl;
		sum += dict[ad[i] - 1] * (dict[len] - dict[ad[i]]);
	}
	cout << sum;
	return 0;
}
