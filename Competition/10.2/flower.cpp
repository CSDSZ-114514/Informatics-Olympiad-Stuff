#include<bits/stdc++.h>
using namespace std;
struct MJ{
	long long t,d;
}mj[10000005];
long long n;
bool cmp(MJ x,MJ y){
	return x.t*y.d<y.t*x.d;
}
int main(){
	freopen("flower.in","read",stdin);
	freopen("flower.out","write",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>mj[i].t>>mj[i].d;
	}
	sort(mj+1,mj+1+n,cmp);
	long long t=0,sf=0;
	for(int i=1;i<=n;i++){
		sf+=(t*mj[i].d);
		t+=2*mj[i].t;
	}
	cout<<sf;
}
