#include<bits/stdc++.h>
using namespace std;

namespace z {
const int N = 1000 + 5, mod = 998244353;
#define int long long
int a[N], b[N];
void main() {
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	int n;cin>>n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		memset(b,-0x3f,sizeof(b));
		for(int i = l; i <= r; i++) {
			for(int j = 1; j + i - 1 <= n; j++) {
				int sum = 0;
				for(int k = j; k <= j + i - 1; k++) {
					sum += a[k];
				}
				for(int k = j; k <= j + i - 1; k++) {
					b[k] = max(b[k], sum);
				}
			}
		}
		unsigned long long ans = 0;
		for(int i = 1; i <= n; i++) ans ^= (i * b[i]);
		cout << ans << '\n';
	}

}

#undef int

} 

int main() {
	z::main();
	return 0;
}

//#include<bits/stdc++.h>
//using namespace std;
//
//namespace z {
//const int N = 10000 + 5, mod = 998244353;
////#define int long long
//int a[N], b[N], s[N], mx[N][N];
//void main() {
//	freopen("query2.in", "r", stdin);
//	freopen("query.out", "w", stdout);
//	int n;cin>>n;
//	for(int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
//	memset(mx,-0x3f,sizeof(mx));
//	for(int i = 1; i <= n; i++) {
//		deque<int> q;
//		for(int j = 1; j + i - 1 <= n; j++) {
//			int v = s[j + i - 1] - s[j - 1];
//			b[j + i - 1] = v;
//		}
//		for(int j = i; j <= n; j++) {
//			while(q.size()&&q.front()+i-1<j)q.pop_front();
//			while(q.size()&&b[q.back()+i-1]<b[j])q.pop_back();
//			q.push_back(j-i+1);
//			mx[i][j]=b[q.front()+i-1]; 
//		}
//		for(int j=1;j<i;j++)mx[i][j]=mx[i][i];
////		cout<<"? "<<i<< " "<<mx[i][i]<<'\n';
//	}
//	int q; cin >> q;
//	while(q--){
//		int l, r; cin >> l >> r;
////		memset(b,-0x3f,sizeof(b));
////		for(int i = l; i <= r; i++) {
////			for(int j = 1; j + i - 1 <= n; j++) {
////				int sum = 0;
////				for(int k = j; k <= j + i - 1; k++) {
////					sum += a[k];
////				}
////				for(int k = j; k <= j + i - 1; k++) {
////					b[k] = max(b[k], sum);
////				}
////			}
////		}
//		unsigned long long ans = 0;
//		for(int i = 1; i <= n; i++) {
//			int res = -2e9;
//			for(int j = l; j <= r; j++) res = max(res,mx[j][i]);
////			cout << res << '\n';
//			ans^=((long long)i*res);
//		}
//		cout << ans << '\n';
//	}
//
//}
//
//#undef int
//
//} 
//
//int main() {
//	z::main();
//	return 0;
//}
