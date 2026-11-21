#include<iostream>

using namespace std;
long long n,m,arr[100005][3],mx1=-1,ans=0;

double mx;

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>arr[i][0]>>arr[i][1];
		arr[i][2]=arr[i][0]+arr[i][1];
		mx1=max(mx1,arr[i][0]);
	}
	
	for(int i=1;i<=n;i++){
		mx1=min(mx1,arr[i][0]);
	}
	ans=m/mx1;
	
	cout<<ans;
	return 0;
}
