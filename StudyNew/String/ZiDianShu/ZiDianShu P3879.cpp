#include <iostream>
#include <vector>
using namespace std;

vector <int> cnt[5000010];
int t[5000010][62], idx;

int ys(char c)
{
	if (c <= 'Z' && c >= 'A')
	{
		return c - 'A';
	}
	if (c <= 'z' && c >= 'a')
	{
		return c - 'a' + 26;
	}
	if (c <= '9' && c >= '0')
	{
		return c - '0' + 52;
	}
	return 12983292;
}

void insert(string s, int k)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int j = ys(s[i]);
		if (!t[p][j])
		{
			idx++;
			t[p][j] = idx;
		}
		p = t[p][j];
	}
	cnt[p].push_back(k);
}

int query(string s)
{
	int p = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int j = ys(s[i]);
		if (!t[p][j])
		{
			return 0;
		}
		p = t[p][j];
	}
	return p;
}

int main(){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++){
		int l;
		cin >> l;
		for (int j = 1; j <= l; j++){
			string s;
			cin >> s;
			insert(s, i);
		}
		
	}
	int m;
	cin >> m;
	for (int j = 1; j <= m; j++)
	{
		string s;
		cin >> s;
		int x = query(s);
		int l = 0;
		for (int y : cnt[x]){
			if (l != y){
				cout << y << ' ';
			}
			l = y;
		}
		cout << '\n';
	}
	return 0;
}