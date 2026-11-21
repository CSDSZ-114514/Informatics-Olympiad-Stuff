#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;

ull a[10005],mod = 1<<32;

int main(){
	freopen("query.in","r",stdin);
    freopen("query.out","w",stdout);
	
	int n;
	cin>>n;
	
	for (int i = 1;i<=n;i++){
		int x;
		cin>>x;
		if (x<0){
			a[i] = mod-abs(x)+mod;
		}
		else a[i] = x;
	}
	
	return 0;
}
