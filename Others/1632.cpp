#include<bits/stdc++.h>
using namespace std;
long long a,b,x,y;
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
	cin>>a>>b;
	long long gd=exgcd(x,y,a,b);
	cout<<(x%(b/gd)+b/gd)%(b/gd);
}
