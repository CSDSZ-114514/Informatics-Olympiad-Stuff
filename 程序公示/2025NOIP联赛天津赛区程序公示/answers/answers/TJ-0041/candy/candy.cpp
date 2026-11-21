#include<bits/stdc++.h>
using namespace std;

long long n, m, k, l, c[100011];
pair<long long, int> b[100011];
pair<long long, pair<long long, int> > a[100011];
map<int, bool> mp;

int main(){
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++){
		scanf("%lld%lld", &a[i].first, &a[i].second.first);
		a[i].second.second = i;
		b[i].first = a[i].first + a[i].second.first;
		b[i].second = i;
	}
	sort(b + 1, b + n + 1);
	sort(a + 1, a + n + 1);
	for(int i = 1;i < n;i += 2){
		if((a[i].first + a[i + 1].first) < b[1].first){
			if((a[i].first+ a[i + 1].first) > m){
				break;
			}
			l = a[i + 1].first;
			m -= (a[i].first + a[i + 1].first);
			mp[i] = mp[i + 1] = 1;
			k += 2;
		}
		else{
			break;
		}
	}
//	cout << k << '\n';
	k += ((m / b[1].first) * 2);
//	cout << k << '\n';
	m %= b[1].first;
	for(int i = 1;i <= n;i++){
		if(mp[i]){
			c[i] = a[i].second.first;
		}
		else{
			c[i] = a[i].first;
		}
	}
	sort(c + 1, c + n + 1);
	for(int i = 1;i <= n;i++){
		if(c[i] <= m){
			k++;
			m -= c[i];
		}
		else{
			break;
		}
	}
/*	cout << '\n' << b[1].first << '\n';
	for(int i = 1;i <= n;i++){
		printf("%lld %lld %lld\n", a[i].first, a[i].second.first, a[i].second.second);
	}
	puts("");
	for(int i = 1;i <= n;i++){
		printf("%lld %lld\n", b[i].first, b[i].second);
	}
	puts("");
	for(int i = 1;i <= n;i++){
		printf("%lld\n", c[i]);
	}*/
	if(l + m >= b[1].first){
		k++;
	}
	printf("%lld", k);
} 
/*
3 15
1 7
2 3
3 1
*/
