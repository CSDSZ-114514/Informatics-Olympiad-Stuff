#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct C{
	int num, sum;
}c[1010], maxn;
int a[1010];
bool cmp(C x, C y){
	return x.num < y.num;
}
int main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= m; i++){
		int f, x, y;
		cin >> f >> x >> y;
		if (f){
			a[x] = y;
		}
		else{
			int cur = 0;
			memset(c, 0, sizeof(c));
			maxn = c[1];
			for (int j = x; j <= y; j++){
				int flag = true;
				for (int k = 1; k <= cur; k++){
					if (a[j] == c[k].num){
						flag = false;
						c[k].sum++;
						break;
					}
				}
				if (flag){
					cur++;
					c[cur].num = a[j];
					c[cur].sum++;
				}
			}
			sort(c + 1, c + cur + 1, cmp);
			for (int j = 1; j <= cur; j++){
				if (c[j].sum > maxn.sum){
					maxn = c[j];
				}
			}
			cout << maxn.num << endl;
		}
	}
	return 0;
}
