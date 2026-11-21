#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue> 
#include<map> 
using namespace std;
int a[1000000];
int BinarySearch2(int x,int s,int b){
	int L=s,R=b,ans;
	int mid = (L+R)/2;
	while(L<=R){
		mid = (L+R)/2;
		if(a[mid]<=x){
			ans = mid;
			L=mid+1;
		}else{
			R=mid-1;	
		}
	}
	return ans;
}
int BinarySearch3(int x,int s,int b){
	int L=s,R=b,ans;
	int mid = (L+R)/2;
	while(L<=R){
		mid = (L+R)/2;
		if(a[mid]>=x){
			ans = mid;
			R=mid-1;
		}else{
			L=mid+1;	
		}
	}
	return ans;
}
int main(){
	int n,t,temp1,temp2,temp3,temp4;
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n); 
	for(int i=1;i<=t;i++){
		cin>>temp1>>temp2;
		temp3=BinarySearch2(temp2,1,n);
		temp4=BinarySearch3(temp1,1,n);
		cout<<temp3-temp4+1<<endl;
	}
	return 0;
} 
