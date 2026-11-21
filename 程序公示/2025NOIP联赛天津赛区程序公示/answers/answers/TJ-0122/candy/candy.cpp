#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100005;
array<ll,3> a[N];
int n,b[N],len;
ll m,ans,now;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%lld%lld",&a[i][1],&a[i][2]);
		a[i][0] = a[i][1]+a[i][2];
	}sort(a+1,a+n+1);
	for(int i = 2;i <= n;i++){
		if(a[i][1]*2 < a[1][0]){
			b[++len] = a[i][1];
			swap(a[i][1],a[i][2]);
		}
	}sort(b+1,b+len+1);
	for(int i = 0;i < len;i++){
		m -= b[i];
		now = m/a[1][0]*2+i;
		if(m % a[1][0] >= b[i+1]){
			now++;
		}ans = max(ans,now);
	}m -= b[len];
	now = m/a[1][0]*2+len;
	m %= a[1][0];
	for(int i = 1;i <= n;i++){
		if(a[i][1] <= m){
			m -= a[i][1];
			now++;
		}
	}
	cout << max(ans,now);
} 
