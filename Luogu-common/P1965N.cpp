#include<iostream>
using namespace std;
int n,m,k,x,b,r,c=1,a[100000005];
int main(){
	cin>>n>>m>>k>>x;
	b=x;
	for(int i=0;;i++){
		x+=m;r++;cout<<r;
		if(x>=n){
			x-=n;
		}
		a[i]=x;cout<<x<<" "<<endl;
		if(x==b){
			break;
		}
	}
	for(int i=1;i<=k;i++){
		c=c*10%r;//cout<<c;
	}
	cout<<a[c];
}
