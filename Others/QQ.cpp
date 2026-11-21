#include<bits/stdc++.h>
using namespace std;
const int maxn = 50;
void getnext(char str[]) {
	int len = strlen(str), i, j, k, temp;
	k = len-2;
	while (k-1 >= 0 && str[k] > str[k + 1]) k--;
	i = k + 1;
	while (i < len && str[i] > str[k]) i++;
	temp = str[k];
	str[k] = str[i-1];
	str[i-1] = temp;
	for (i = len-1; i > k; i--)
		for (j = k + 1; j < i; j++)
			if (str[j] > str[j + 1]) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
	return;
}
int main() {
	char a[maxn];
	int n;
	cin >> a >> n;
	while (n > 0) {
		getnext(a);
		n--;
	}
	cout << a << endl;
	return 0;
}
