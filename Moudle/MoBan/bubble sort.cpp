#include<iostream>
using namespace std;
int a[10000];
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=2;i--){ //�Ӻ���ǰ 
		for(int j=1;j<i;j++){
			if(a[j+1]<a[j]){ //���� 
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=1;i<=n-1;i++){ //��ǰ���� 
		for(int j=n;j>i;j--){
			if(a[j]<a[j-1]){ //���� 
				swap(a[j],a[j-1]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
