#include <iostream>
using namespace std;
long long phi[10000010], p[10000010], d[10000010];
long long cnt = 0;
void get_phi(long long n){
	phi[1] = 1;
	for (long long i = 2; i <= n; i++){
		if (phi[i] == 0){
			phi[i] = i - 1;
			cnt++;
			p[cnt] = i;
		}
		for (long long j = 1; j <= cnt && p[j] * i <= n; j++){
			if (i % p[j] == 0){
				phi[p[j] * i] = p[j] * phi[i];
				break;
			}
			else{
				phi[p[j] * i] = (p[j] - 1) * phi[i];
			}
		}
	}
	for (long long i = 1; i <= n; i++){
		d[i] = d[i - 1] + phi[i];
	}
}

int main(){
	long long n;
	cin >> n;
	get_phi(n);
	long long sum = 0;
	for (long long i = 1; i <= cnt; i++){
		sum += 2 * d[n / p[i]] - 1;
	}
	cout << sum;
	return 0;
}