#include<bits/stdc++.h>
using namespace std;
int main(){
	double a=0,temp=0;cin>>a;
//	for(int i=1;i<=a;i++){
//		if(i*i>=a){
//			temp=i;
//			break;
//		}
//	}
//	while(true){
//		temp=-1*(temp*temp-a)/(2*temp)+temp;
//		if(abs(temp*temp-a)<=0.000000001){
//			break;
//		}
//	}
//	cout<<fixed<<setprecision(12);
//	cout<<temp;
	cout<<sqrt(a)<<" "<<pow(a,1/2.0);
}
