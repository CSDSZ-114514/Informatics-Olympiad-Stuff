#include<bits/stdc++.h>
using namespace std;
long long n,m,sum=0;
struct ILoveLrh{
	long long x,y,c;
}a[100020];
bool cmp(ILoveLrh tq,ILoveLrh qt){ 
	return tq.c<qt.c;
}
bool pmc(ILoveLrh tq,ILoveLrh qt){ 
	return tq.x<qt.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].c=a[i].x+a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	/*for(int i=1;i<=n;i++){
		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].c<<endl;
	}*/
	//cout<<endl<<endl;
	for(int i=2;i<=n;i++){
		if(a[i].x<=a[1].y){
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].c<<endl;
			m-=a[i].x;
			swap(a[i].x,a[i].y);
			sum++;
		}
	}
	for(int i=2;i<=n;i++){
		if(a[i].x<=a[1].y){
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].c<<endl;
			m-=a[i].x;
			swap(a[i].x,a[i].y);
			sum++;
		}
	}
	//cout<<"\n\n";
	sum+=(m/a[1].c);
	sum+=(m/a[1].c);
	m%=a[1].c;
	sort(a+1,a+n+1,pmc);
	/*for(int i=1;i<=n;i++){
		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].c<<endl;
	}*/
	//cout<<"\n\n";
	for(int i=1;i<=n;i++){
		if(a[i].x<=m){
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].c<<endl;
			m-=a[i].x;
			swap(a[i].x,a[i].y);
			sum++;
		}
	}
	sort(a+1,a+n+1,pmc);
	for(int i=1;i<=n;i++){
		if(a[i].x<=m){
			//cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].c<<endl;
			m-=a[i].x;
			swap(a[i].x,a[i].y);
			sum++;
		}
	}
	cout<<sum<<endl;
	return 0;
}
