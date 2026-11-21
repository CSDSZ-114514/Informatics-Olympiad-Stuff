#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N=1e5+10;
int n,m,s[N],ans,ind;
struct node{
	int x,y,s,id;
} l[N],a[N];

bool cmp1(node A,node B){
	if(A.s!=B.s) return A.s < B.s;
	if(A.x!=B.x) return A.x < B.y;
	return A.id < B.id;
}
bool cmp2(node A,node B){
	if(A.x!=B.x) return A.x < B.x;
	return A.id < B.id;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> l[i].x >> l[i].y;
		l[i].s=l[i].x+l[i].y, a[i].x=l[i].x;
		l[i].id=a[i].id=i;
	}
	sort(l+1,l+n+1,cmp1);
	sort(a+1,a+n+1,cmp2);
	for(int i=0;i<=n;i++){
		if(a[i].id!=l[1].id){
			s[i]=s[i-1]+a[i].x;
		}
		else{
			ind=i;
			s[i]=s[i-1]; // 不将总和最小的计入前缀和，因为其要单独计算
		}
	}
	
	int tmp,cnt;
	for(int i=0;i<=n;i++){ 
		if(s[i]>m || a[i].x>=l[1].s) break;
		tmp=m-s[i];
		cnt=2*(tmp/l[1].s)+(tmp%l[1].s>=l[1].x); // 这里不需要判>=min(l[1].x, a[i+1].x)，因为后面会判到的 
		ans=max(ans,cnt+i-(i>=ind));
	}
	cout << ans;
	return 0;
} 
