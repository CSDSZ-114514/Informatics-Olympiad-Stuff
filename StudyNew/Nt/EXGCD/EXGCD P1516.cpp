#include<bits/stdc++.h>
using namespace std;
long long exgcd(long long a,long long b,long long &x,long long &y){
    if(b==0){
        x=1;y=0;
        return a;
    }
    long long x1=0,y1=0,d=0;
    d=exgcd(b,a%b,x1,y1);
    x=y1,y=x1-a/b*y1;
    return d;
}
long long x,y,m,n,l;
int main(){
    cin>>x>>y>>m>>n>>l;
	if(n-m<0){
		swap(n,m);
		swap(x,y);
	}
    long long x2=0,y2=0;
	long long d=exgcd(n-m,l,x2,y2);
    if((x-y)%d!=0){
        cout<<"Impossible";
    }else{
        cout<<((x2*(x-y)/d)%(l/d)+(l/d))%(l/d);
    }
    return 0;
}