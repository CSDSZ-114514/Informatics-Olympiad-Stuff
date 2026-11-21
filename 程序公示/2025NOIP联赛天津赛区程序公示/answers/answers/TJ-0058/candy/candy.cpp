#include<bits/stdc++.h>

using namespace std;
long long n,m,b[100005],ans,minn;
struct str{
	long long x,y;
};
str a[100005];
int cmp1(str o,str p){
	if(o.x+o.y==p.x+p.y) return o.x<p.x;
	return o.x+o.y<p.x+p.y;
}
int cmp2(str o,str p){
	if(o.x==p.x) return o.y<p.y;
	return o.x<p.x; 
} 
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
	}
	sort(a+1,a+1+n,cmp1);
	minn=a[1].x+a[1].y;
	sort(a+2,a+1+n,cmp2);
	int l=2,r=n;
	for(int i=2;i<=n;i++){
		long long z;
		z=a[i].x;
		if(b[1]==0){
			if(z<a[1].y){
				ans+=2;
				b[i]++;
				b[1]++;
				m-=(a[1].x+z);
			}
		}else if(b[1]==1){
			if(z<a[1].x){
				ans+=2;
				b[i]++;
				b[1]++;
				m-=(a[1].y+z);
			}
		}
		b[i]%=2;
		b[1]%=2;
	}
	ans+=m/minn*2;
	m%=minn;
	for(int i=2;i<=n;i++){
		long long t;
		if(b[i]==0) t=a[i].x;
		if(b[i]==1) continue;
		if(a[1].x<t&&b[1]==0){
			if(a[1].x<=m){
				ans++;
				m-=a[1].x;
				b[1]=1;
			}else break;
		}
		if(t<=m){
			ans++;
			m-=t;
		}else break;
	}
	cout<<ans;
	return 0;
} 
