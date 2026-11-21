#include<bits/stdc++.h>
using namespace std;
int t;
int n,m;
struct T{
	int v;
	int p;
	int s;
	int num;
	int d;
}a[8010];
void get_d(int x){
	if(x==1||a[x].d!=0) return ;
	get_d(a[x].p);
	a[x].d=a[a[x].p].d+1;
	return ;
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	cin>>t;
	while(t--){
		cin>>n>>m;
		a[1].num=1;
		for(int i=2;i<=n;i++){
			cin>>a[i].p;
			a[a[i].p].s++;
			a[i].num=i;
		}
	}
	return 0;
}
