#include<bits/stdc++.h>
using namespace std;
const int N=1e5+100;
int n;
long long m;
struct Candy{
	long long x,y;
	long long sum;
}a[N];
long long s[N];
long long t;
long long mn=0x7fffffff;
long long mxx;
long long f;
long long flag;
long long ans;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	cin>>n;
	cin>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].sum=a[i].x+a[i].y;
		if(a[i].sum<mn){
			mxx=a[i].x;
			mn=a[i].sum;
			f=i;
		}
		if(a[i].sum==mn&&a[i].x>mxx){
			mxx=a[i].x;
			mn=a[i].sum;
			f=i;
		}
	}
	for(int i=1;i<=n;i++){
		s[++t]=a[i].x;
	}
	sort(s+1,s+1+t);
	for(int i=1;i<=t;i++){
		if(s[i]*2<a[f].sum&&m>=s[i]){
			ans++;
			m-=s[i];
		} 
		else{
			flag=i-1;
			break;
		}
	}
	ans+=m/a[f].sum*2;
	m-=m/a[f].sum*a[f].sum;
	if(m+s[flag]>=a[f].sum||m>=s[flag+1]) ans++;
	cout<<ans;
	return 0;
} 
