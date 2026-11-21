#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;cin >> n >> m;
	long long h[n],hh[n],x=1e10,z=1e9;
	for (int i=0;i<n;i++){
		cin >> h[i] >> hh[i];
		x=min(x,h[i]);
		long long a=h[i]+hh[i];
		z=min(z,a);
	}
	long long my=(m/z)*2;
	m=m%z;
	sort(h,h+n);
	cout << m << endl;
	for (int i=0;i<n;i++){
		if (h[i]<=m){
			my=my+1;
			m-=h[i];
		}
		else if(h[i]>m) break;
	}
	cout << my;
	return 0;
} 
