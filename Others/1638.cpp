#include<bits/stdc++.h>
using namespace std;
long long n,m,x,y,l;
long long x2,y2;
long long exgcd(long long &x,long long &y,long long a,long long b){
	if(b==0){
		x=1;y=0;
		return a;
	}else{
		long long x1=0,y1=0;
		long long d=exgcd(x1,y1,b,a%b);
		x=y1;
		y=x1-a/b*y1;
		return d;
	}
}
int main(){

	cin>>x>>y>>m>>n>>l;
	if(n-m<0){
		swap(n,m);
		swap(x,y);
	}
	long long d=exgcd(x2,y2,n-m,l);
	if((x-y)%d!=0){
		cout<<"Impossible";
	}
	else{
		cout<<((x2*(x-y)/d)%(l/d)+l/d)%(l/d);
	}
		
}
