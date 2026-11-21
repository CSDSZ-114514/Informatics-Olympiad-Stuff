#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct PT{
	long long L,R;
	long long sum,add; 
}tr[800005],tr2[800005];
void build(long long p,long long l,long long r) {
	tr[p]={l,r,0}; 
	if(l==r){ 
		tr[p].sum=0; 
		return;
	}
	long long mid=(l+r)>>1; 
	build(2*p,l,mid); 
	build(2*p+1,mid+1,r); 
}
void pushdown(long long p) {
	if(tr[p].add) {
		tr[2*p].sum+=(tr[2*p].R-tr[2*p].L+1)*tr[p].add;
		tr[2*p].add+=tr[p].add;
		tr[2*p+1].sum+=(tr[2*p+1].R-tr[2*p+1].L+1)*tr[p].add;
		tr[2*p+1].add+=tr[p].add;
		tr[p].add=0; 
	}
}
void update(long long p,long long x,long long y,long long k) {
	if(x<=tr[p].L&&tr[p].R<=y) {  
		tr[p].sum+=(tr[p].R-tr[p].L+1)*k; 
		tr[p].add+=k; 
		return; 
	}
	pushdown(p); 
	long long mid=(tr[p].L+tr[p].R)>>1;
	if(x<=mid){ 
		update(2*p,x,y,k); 
	}
	if(y>mid){  
		update(2*p+1,x,y,k); 
	}
	tr[p].sum=tr[2*p].sum+tr[2*p+1].sum; 
}
long long query(long long p,long long x,long long y) {
	if(x<=tr[p].L&&tr[p].R<=y) {  
		return tr[p].sum; 
	}
	pushdown(p); 
	long long mid=(tr[p].L+tr[p].R)>>1;
	long long sum=0;
	if(x<=mid){ 
		sum+=query(2*p,x,y); 
	}
	if(y>mid) { 
		sum+=query(2*p+1,x,y); 
	}
	return sum;
}

void build2(long long p,long long l,long long r) {
	tr2[p]={l,r,0}; 
	if(l==r){ 
		tr2[p].sum=0; 
		return;
	}
	long long mid=(l+r)>>1; 
	build2(2*p,l,mid); 
	build2(2*p+1,mid+1,r); 
}
void pushdown2(long long p) {
	if(tr2[p].add) {
		tr2[2*p].sum+=(tr2[2*p].R-tr2[2*p].L+1)*tr2[p].add;
		tr2[2*p].add+=tr2[p].add;
		tr2[2*p+1].sum+=(tr2[2*p+1].R-tr2[2*p+1].L+1)*tr2[p].add;
		tr2[2*p+1].add+=tr2[p].add;
		tr2[p].add=0; 
	}
}
void update2(long long p,long long x,long long y,long long k) {
	if(x<=tr2[p].L&&tr2[p].R<=y) {  
		tr2[p].sum+=(tr2[p].R-tr2[p].L+1)*k; 
		tr2[p].add+=k; 
		return; 
	}
	pushdown2(p); 
	long long mid=(tr2[p].L+tr2[p].R)>>1;
	if(x<=mid){ 
		update2(2*p,x,y,k); 
	}
	if(y>mid){  
		update2(2*p+1,x,y,k); 
	}
	tr2[p].sum=tr2[2*p].sum+tr2[2*p+1].sum; 
}
long long query2(long long p,long long x,long long y) {
	if(x>y)return 0;
	if(x<=tr2[p].L&&tr2[p].R<=y) {  
		return tr2[p].sum; 
	}
	pushdown2(p); 
	long long mid=(tr2[p].L+tr2[p].R)>>1;
	long long sum=0;
	if(x<=mid){ 
		sum+=query2(2*p,x,y); 
	}
	if(y>mid) { 
		sum+=query2(2*p+1,x,y); 
	}
	return sum;
}
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	build(1,1,n);
	build2(1,1,n);
	for(int i=1;i<=m;i++){
		long long q,l,r;
		cin>>q>>l>>r;
		if(q&1){
			update(1,l,l,1);
			update2(1,r,r,1);
		}else{
			cout<<query(1,1,r)-query2(1,1,l-1)<<'\n';
		}
	}
	return 0;
}
