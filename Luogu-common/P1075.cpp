#include <bits/stdc++.h>
using namespace std;
long long n;
int main() {
	cin>>n;
	for (long long i=2;i<=sqrt(n);i++) {
		if (n % i == 0) { 
			cout << n/i;
			break;
		}
	}	
	return 0;
}
