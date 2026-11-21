#include<iostream>
using namespace std;
int a[10000], b[10000], s[10000];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (b[ a[i] ] == 0) b[ a[i] ] = i;
		s[ b[ a[i] ] ] += a[i];
	}
	int sum1 = 0, sum2 = 0, sum3 = 0;
	for(int i = 0; i < 10000; i++) {
		if (b[i] != 0 ) sum1++;
		if (s[ b[i] ] != 0) sum2 += s[ b[i] ] / a[ b[i] ];
	}
	for(int i = 1; i <= n; i++) {
		if (b[ a[i] ] != i) sum3++;
	}
	cout << sum1 << " " << sum2 << " " << sum3 << endl;
	int maxs = 0;
	for (int i = 0; i < 10000; i++) {
		if(s[i] > maxs) maxs = s[i];
	}
	cout << maxs << endl;
	return 0;
}
