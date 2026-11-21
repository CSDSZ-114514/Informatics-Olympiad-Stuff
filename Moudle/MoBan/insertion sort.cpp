#include<iostream>
using namespace std;
int a[10000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=2;i<=n;i++){
		for(int j=i;j>=2;j--){
			if(a[j]<a[j-1]){
				swap(a[j],a[j-1]);
			}else{
				break;
			}
		}
	} 
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
