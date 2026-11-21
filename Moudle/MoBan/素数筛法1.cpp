#include<iostream>
#include<algorithm> 
#include<cmath>
using namespace std;
int a[1000005];
void soe(){
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=1000000;i++){
		if(a[i]==0){
			for(int j=2;i*j<=1000000;j++){
				a[i*j]=1;
			}
		}
	}
}
int main(){
	soe();
	int N,sum=0;
	cin>>N;
	for(int i=1;i<=N;i++){
		if(a[i]==0&&a[N-i+1]==0){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
