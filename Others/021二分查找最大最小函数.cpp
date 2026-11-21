#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],t,t1,t2;
int erfe_bg(int in){
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]>=in){
			r=mid-1;
			ans=mid;
		}else{
			l=mid+1;
		}
	}
	
	return ans;
}
int erfe_sm(int in){
	int ans=0;
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(a[mid]<=in){
			
			ans=mid;
			l=mid+1;
		}else {
			r=mid-1;
			
		}
	}
	return ans;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>t1;
		cin>>t2;
		if(t1>a[n]){
			cout<<0<<endl;
			continue;
		}
		if(t2<a[1]){
			cout<<0<<endl;
			continue;
		}
//		cout<<erfe_sm(t2)-erfe_bg(t1)+1<<endl;
		int index = lower_bound(a+1,a+n+1,t1)-a;//>=x
		int index2=upper_bound(a+1,a+n+1,t2)-a;//>x
		cout<<index2-index;
	}
}
