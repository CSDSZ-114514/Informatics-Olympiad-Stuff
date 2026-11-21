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
		if(a[mid]>=x){
			ans = a[mid];
			R=mid-1;
		}else{
			L=mid+1;	
		}
	}
	return ans;
}
int main(){
	int n,t,s;
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n);
	for(int i=1;i<=t;i++){
		cin>>s;
		cout<<BinarySearch2(s,1,n)<<endl;
	}
	return 0;
} 
