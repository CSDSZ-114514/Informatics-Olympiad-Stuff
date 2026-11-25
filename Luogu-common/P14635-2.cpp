#include<bits/stdc++.h>
using namespace std;
long long n,m; 
struct CD{
	long long x,y;
	bool operator<(const CD p)const{
		return x<p.x;
	}
}cd[10000005];
int main(){
	cin>>n>>m;
	long long bst=1e18;
	for(int i=1;i<=n;i++){
		cin>>cd[i].x>>cd[i].y;
		bst=min(bst,cd[i].x+cd[i].y);
	}
	sort(cd+1,cd+1+n);
	long long ans=0,qzh=0;
	for(int i=0;i<=n;i++){
		qzh += cd[i].x;
		if(qzh>m)break;
		ans=max(ans,2*((m-qzh)/bst)+i);
	}
	cout<<ans;
	return 0;
}
