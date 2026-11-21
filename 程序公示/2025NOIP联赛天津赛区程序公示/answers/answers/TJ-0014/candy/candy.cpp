#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m;
struct Node{
	int x,y,nw,p,ty;//1 x 2 y 3 z
	bool operator < (const Node &c)const{
		if(c.nw==nw) return c.y<y;
		return c.nw<nw;
	} 
}a[100055];
struct Node1{
	int x,p;
	bool operator < (const Node1 &c)const{
		return c.x<x;
	} 
}b[100055];
priority_queue<Node> q;
priority_queue<Node1> q1;
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);	
	cin.tie(0),ios_base::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].nw=a[i].x,a[i].ty=1,a[i].p=i;
		b[i].x=(a[i].x+a[i].y),b[i].p=i;
		q.push(a[i]);
		q1.push(b[i]);
	}
	int ans=0;
	for(int i=1;i<=2*n;i++){
		Node x=q.top();
		Node1 y=q1.top();
	//	cout<<"#"<<x.x<<" "<<x.y<<" "<<y.x<<" "<<x.p<<" "<<y.p<<"\n";
		if(x.nw*2<y.x){
			if(m<x.nw){
				cout<<ans<<"\n";
				return 0;
			}
			ans++;
			m-=x.nw;
			x.ty++;
			if(x.ty%2==0) x.nw=x.y;
			else x.nw=x.x;
			q.pop();
			q.push(x);
		}else {
			if(m>=y.x){
				int k=m/y.x,kk=m%y.x;
				ans+=(2*k);
				m=kk;
				break;
			}else{
				break;
			}
		}
		
	}
	for(int i=1;i<=3*n;i++){
		Node x=q.top();
		//cout<<m<<" "<<x.nw<<" "<<x.x<<" "<<x.y<<"\n"; 
		if(m>=x.nw){
			ans++;
			m-=x.nw;
			x.ty++;
			q.pop();
			if(x.ty%2==0) 	x.nw=x.y;
			else x.nw=x.x;
			q.push(x);
		}else {
			cout<<ans<<"\n";
			return 0;
		}
	}
	cout<<ans<<"\n";
	return 0;
}

