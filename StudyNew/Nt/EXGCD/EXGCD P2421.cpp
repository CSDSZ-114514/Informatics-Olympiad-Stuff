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
long long n,c[100005],p[100005],l[100005];
int main(){
    cin>>n;
    long long mx=-1e9;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>p[i]>>l[i];
        mx=max(mx,c[i]);
    }
    long long ab=0;
	for(int k=mx;;k++){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                long long a=p[i]-p[j],b=k,t=c[j]-c[i],x=0,y=0;
                if(a<0){
                    a=-a;t=-t;
                }
                long long d=exgcd(a,b,x,y);
		        if(t%d) continue;
                x=(x*t/d%(b/d)+b/d)%(b/d);
                if(x<=l[i]&&x<=l[j])goto aaaaaa;
            }
        }
        cout<<k;return 0;
        aaaaaa:;
    }
    return 0;
}