#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue> 
#include<map> 
using namespace std;
int a[1000000];
bool BinarySearch(int x,int s,int b){
	int L=s,R=b;
	int mid = (L+R)/2;
	while(L<=R){
		mid = (L+R)/2;
		if(a[mid]==x){
			return true;
		}
		if(a[mid]>x){
			R=mid-1;
		}
		if(a[mid]<x){
			L=mid+1;
		}
	}
	return false;
}
int main(){
	int c,b,d;
	cin>>c;
	for(int i=1;i<=c;i++){
		cin>>a[i];
	}
	cin>>b;
	for(int i=1;i<=b;i++){
		cin>>d;
		if(BinarySearch(d,1,c)){
			cout<<"Yes";
		}else{
			cout<<"No";
		}
	}
	return 0;
} 
