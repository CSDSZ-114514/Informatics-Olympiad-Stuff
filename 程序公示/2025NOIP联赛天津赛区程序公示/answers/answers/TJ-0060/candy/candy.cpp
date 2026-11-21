#include<bits/stdc++.h>
#define int long long
using namespace std;    
struct candy{
	int x;
	int y;
};
candy c[100005];
bool comp(const candy& a,const candy& b){
	return a.x<b.x;//shengxv
} 
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int d[100005];
	for(int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
		d[i]=c[i].x+c[i].y;
	}
	sort(c+1,c+n+1,comp);
	sort(d+1,d+n+1);
	int ans=0;
	int reg=0;
	int i;
	for(i=1;i<=n;i++){
		if((c[i].x)*2<d[1]){
			m=m-c[i].x;
			ans++;
			reg=c[i].x;
			c[i-1].x=c[n].x;
		}
		else break;
	}
	ans+=(m/d[1])*2;
	int w=m%d[1];
	if(w+reg>d[1]){
		ans++;
		w=w+c[i-1].x-d[1];
	}
	else c[i-1].x=c[n].x;
	for(int j=1;j<=n;j++){
		if(w>=c[j].x){
			w=w-c[j].x;
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 

