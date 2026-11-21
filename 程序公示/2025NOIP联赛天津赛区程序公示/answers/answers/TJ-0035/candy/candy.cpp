#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct abc{
	long long x,y,s,i;
}a[100005];
long long x[100005];
long long mins=LONG_LONG_MAX;
bool cmp(abc a,abc b){
	if (a.x==b.x){
		return a.s<b.x;
	}return a.x<b.x;
}long long s;
int X;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].i=i;
		a[i].s=(a[i].x+a[i].y);
		mins=min(a[i].s,mins);
		x[i]=a[i].x;
	}sort(a,a+n,cmp);
	while (X<n && a[X].x*1.0<=mins*1.0/2){
		s+=1;
		m-=a[X].x;
		x[a[X].i]=a[X].y;
		X++;
	}s+=(m/mins)*2;
	m%=mins;
	X--;
	if (a[X].x+m>=mins){
		s++;
	}else{
		for (int i=0;i<n;i++){
			if (x[i]<=m){
				s++;
				break;
			}
		}
	}cout<<s;
	return 0;
} 

