#include<bits/stdc++.h>
using namespace std;
long long n,k,fa[1000005];
long long find(long long x) {
	if(x==fa[x]) {
		return x;
	} else {
		return fa[x]=find(fa[x]);
	}
}
struct ED{
	long long u,v,w;
}a[10000005];
long long cnt,cnt1=0;
struct PT{
	long long x,y; 
}b[10000005];
bool cmp(ED x,ED y){
	return x.w<y.w;
}
long long wal[1000005];
bool cmp2(long long x,long long y){
	return x>y;
}
double kruskal(){
	for(int i=1;i<=n;i++)fa[i]=i;
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++) { 
		long long x=find(a[i].u); 
		long long y=find(a[i].v);
		if(x!=y) {
			wal[++cnt1]=a[i].w;
			fa[x]=y; 
		}
	}
	sort(wal+1,wal+cnt1+1,cmp2);
	return sqrt(wal[k-1]);
}

int main(){
	freopen("tribe.in","r",stdin);
	freopen("tribe.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++){
		cin>>b[i].x>>b[i].y;
		for(int j=1;j<i;j++){
			a[++cnt].u=j;
			a[cnt].v=i;
			a[cnt].w=(b[i].x-b[j].x)*(b[i].x-b[j].x)+(b[i].y-b[j].y)*(b[i].y-b[j].y);
			//cout<<a[cnt].w<<'\n';
		}
	}
	cout<<fixed<<setprecision(2)<<kruskal();
	return 0;
} 
