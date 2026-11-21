#include<bits/stdc++.h>

using namespace std;
const long long N=998244353;
int c,t;
int n,m;
long long sum=0,pd=0;
struct node{
	int a,xb;
	int w;
}a[5005];
bool cmp(node x,node y){
	if ((double)x.a/x.w==(double)y.a/y.w){
		if (x.a==y.a){
			return x.xb<y.xb;
		}else{
			return x.a>y.a;
		}
	}else{
		return (double)x.a/x.w>(double)y.a/y.w;
	}
}
void dg(int x){
	if (x>n){
		node a1[5005];
		for (int i=1;i<=n;i++){
			a1[i]=a[i];
		}
		sort(a1+1,a1+n+1,cmp);
		long long g=0,m2=0;
		for (int i=1;i<=n;i++){
			if (a[i].w==1&&m2+1>m)break;
			if (m2+a[i].w<=m){
				m2+=a[i].w;
				g+=a[i].a;
			}
		}
		if (g>=pd)sum++;
	}else{
		a[x].w=1;
		dg(x+1);
		a[x].w=2;
		dg(x+1);
	}
	return;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while (t--){
		scanf("%d%d",&n,&m);
		sum=0;
		pd=0;
		for (int i=1;i<=n;i++){
			scanf("%d",&a[i].a);
			a[i].xb=i;
			a[i].w=2;
		}
		sort(a+1,a+n+1,cmp);
//		for (int i=1;i<=n;i++){
//			cout<<a[i].a<<' '<<a[i].w<<' '<<a[i].xb;
//			cout<<endl;
//		}
//		
		int m1=0;
		for (int i=1;i<=n;i++){
			if (m1+a[i].w>m)break;
			m1+=a[i].w;
			pd+=a[i].a;
		}
		dg(1);
		printf("%lld\n",sum);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
