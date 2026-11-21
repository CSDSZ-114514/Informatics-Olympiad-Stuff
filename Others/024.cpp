#include<bits/stdc++.h>
using namespace std;
long long L,R,n,a[10000005],x,y,sum;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
	}	cin>>L>>R;
	for(int i=1;i<=n;i++){
		if(a[i]>R){
			x+=(a[i]-R);
		}
		if(a[i]<L){
			y+=(L-a[i]);
		}
	}
	if(sum>R*n||sum<L*n){
		cout<<-1;
		return 0;
	}
	cout<<max(x,y);
	
}
