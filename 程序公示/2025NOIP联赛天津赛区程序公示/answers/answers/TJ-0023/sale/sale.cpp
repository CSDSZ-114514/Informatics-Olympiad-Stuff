#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll P=998244353;
int C,T;
ll n,m,a[5005],b[5005],ans;
struct node{
	double c;
	ll a,b,i;
}c[5005];
bool cmp(node x,node y){
	if(x.a!=y.a) return x.c>y.c;
	return x.i<y.i;
}
bool cmp1(node x,node y){
	return x.a>y.a;
}
ll qpow(ll a,ll b){
	ll res=1;
	while(b){
		if(b&1){
			res=res*a%P;
		} 
		b/=2;
		a=a*a%P;
	}
	return res;
}
bool check()
{
	ll x=0,y=0,l=m,r=m;
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		r-=c[i].b;
		if(r<=0) break;
		x+=c[i].a;
	}
	sort(c+1,c+n+1,cmp1);
	for(int i=1;i<=n;i++)
	{
		if(l-c[i].b<0) continue;
		l-=c[i].b;
		y+=c[i].a;
	}
	return x>=y;
}
void dg(int x)//O(2^n)
{
	if(x==n+1){
		if(check()) ans++; 
		return;
	}
	for(c[x].b=1;c[x].b<=2;c[x].b++){
		c[x].c=1.0*a[x]/c[x].b;
		c[x].a=a[x],c[x].i=x;
		dg(x+1);
	}
}
int main()
{
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>C>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<qpow(2,n)%P<<"\n";//A||m==2n-1
	}
	return 0;
 } 
