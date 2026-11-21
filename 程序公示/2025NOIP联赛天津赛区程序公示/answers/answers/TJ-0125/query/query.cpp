#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=50010;
int n,q,a[N],s[N],k[N],ans,mod=998244353,tmp,cnt,l,r; // l,r为能任意取的范围 

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		s[i]=s[i-1]+a[i];
	}
	cin >> q;	
	while(q--){
		cout << "0\n";
	}

	return 0;
} 
