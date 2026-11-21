#include<iostream>
using namespace std;
int bucket[1000];
int main(){
	int n,b;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b;
		bucket[b]++;
	}
	for(int i=0;i<=1000;i++){
		while(bucket[i]!=0){
			cout<<i<<" ";
			bucket[i]--;
		}
	}
	return 0;
}
