#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int const N=100010;
int n;
ll res1,res2;
ll m,k,p;

struct node{
	ll x,y,s,id;
} t[N];

bool cmp1(node a,node b){
	if (a.s==b.s) return a.x<b.x;
	return a.s<b.s;
}


bool cmp2(node a,node b){
	return a.x<b.x;
}

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	scanf("%d %lld",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d %d",&t[i].x,&t[i].y);
		t[i].s=t[i].x+t[i].y;
		t[i].id=i;
	}
	ll cnt=0;
	//type 1:buy every candy once
	sort(t+1,t+n+1,cmp2);
	for (int i=1;i<=n;i++){
		cnt+=t[i].x;
		if (cnt<=m) res1++;
	}
	//type 2
	sort(t+1,t+n+1,cmp1);
	k=t[1].s,p=t[1].id;
	sort(t+1,t+n+1,cmp2);
	cnt=m;
	for (int i=1;i<n;i++){
		if (t[i].x+t[i+1].x<k || cnt<k){
			if (t[i].x<=cnt){
				res2++;
				cnt-=t[i].x;
			}
			else break;
		}
		else{
			res2+=cnt/k*2,cnt%=k,i--;
			continue;
		}
		if (!cnt) break;
		if (i==n-1){
			if (t[i+1].x<=cnt) res2++;
		}
	}
	if (res1<res2) printf("%lld",res2);
	else printf("%lld",res1);
	
	
	return 0;
} 
