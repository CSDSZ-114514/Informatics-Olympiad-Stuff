#include<bits/stdc++.h>
using namespace std;

struct Candy{
	long long j;
	long long o;
	long long t;
	int num;
};
bool cmp(Candy c1,Candy c2){
	return c1.j<c2.j;
}
Candy c[200000];
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long mn=1145141919810;
	int mnp=0;
	for(int i=1;i<=n;i++){
		cin>>c[i].j>>c[i].o;
		c[i].num=i;
		c[i].t=c[i].j+c[i].o;
	}
	sort(c+1,c+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(c[i].t<mn){
			mn=c[i].t;
			mnp=i;
		}
	}
	long long fans=0;
	long long ans=m/mn;
	ans=ans*2;
	long long bymn=ans;
	int y=m%mn;

	/*for(int i=1;i<=n;i++){
		cout<<i<<" "<<c[i].j<<" "<<c[i].o<<"\n";
	}*/
	int i=0;int ttt=0;
	while(i<n&&bymn>0){
		while(y>=c[i+1].j&&i<n){
			//cout<<" new"<<y<<" "<<c[i+1].j<<" "<<ans<<" "<<i<<"\n";
			y-=c[i+1].j;
			i++;
			ans++;
		}
		//cout<<ans<<" "<<i<<" "<<y<<"\n";
		fans=max(fans,ans);
		bymn-=2;
		ans-=2;
		ttt++;
		if(ttt>114514){
			break;
		}
		y+=mn;
	}
	cout<<fans;
	return 0;
}
