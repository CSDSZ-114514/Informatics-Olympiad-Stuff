#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL len,n,m,a[50005],a0,a1;
bool check(LL k){
	LL las=a0,num=0;
	for(int i=1;i<=n+1;i++){
		if(a[i]-las<k){
			num++;
		}else{
			las=a[i];
		}
	}
	if(num>m){
		return false;
	}else{
		return true;
	}
}
LL bs(){
	LL l=1,r=len,ans=0;
	while(l<=r){
		LL mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	return ans;
}
int main(){
	cin>>len>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	a0=0;
	a[n+1] = len;
	cout<<bs();
	
}
