#include<bits/stdc++.h>
using namespace std;
long long a,b,minn=1e9;
long long exgcd(long long a,long long b,long long &x,long long &y) {
	if(b==0){ 
		x=1,y=0;
		return a;
	}
	long long x1=0,y1=0;
	long long d=exgcd(b,a%b,x1,y1); 
	x=y1; 
	y=x1-a/b*y1;
	return d;
}
int main(){
	cin>>a>>b;
//	for(int i=2;i<=4000;i++){
//		if((i*b-(i-1)*a)>0){
//			minn=min((i*b-(i-1)*a)%a,minn);
//		}
//	}
//	cout<<minn;
	long long ta,tb,d=exgcd(a,b,ta,tb);
	cout<<d<<endl;
	ta*=-1;
	long long dx=(ta%(b/d)+(b/d))%(b/d);
	cout<<dx<<" "<<(d+a*dx)/b;
	return 0;
}
