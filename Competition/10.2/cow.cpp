#include<bits/stdc++.h>
using namespace std;
long long n,p,c[10000005];
struct ED{
	long long u,v,w;
}e[1000005];

long long fa[1000005];
long long find(long long x) {
	if(x==fa[x]) {
		return x;
	} else {
		return fa[x]=find(fa[x]);
	}
}
void heb(long long x, long long y) {
	fa[find(x)]=find(y);
} 
bool cmp(ED x,ED y){
	return x.w<y.w;
}
long long kk(){
	long long res=0;
	for(int i=1;i<=p;i++) { 
		long long u=find(e[i].u); 
		long long v=find(e[i].v);
		if(u!=v) { 
			res+=e[i].w;
			fa[u]=v;
		}
	}
	return res;
}
int main(){
	freopen("cow.in","read",stdin);
	freopen("cow.out","write",stdout);
	cin>>n>>p;
	for(int i=1;i<=n;i++)cin>>c[i];
	long long mins=1e18;
	for(int i=1;i<=n;i++)mins=min(mins,c[i]);
	for(int i=1;i<=p;i++){
		long long x,y,z;cin>>x>>y>>z;
		e[i]={x,y,2*z+c[x]+c[y]};
	}
	for(int i=1; i<=n; i++)fa[i]=i;
	sort(e+1, e+p+1, cmp);
	cout<<kk()+mins;
	return 0;
} 
