#include<iostream>
#include<algorithm>
using namespace std;
int a[5000];
bool cmp1(int x,int y){
	if(x<y){
		return true; //true不能包含等于的情况 
	}else{
		return false;
	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp1);
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
