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
	cout<<"test1:";
	soe();
	cout<<"test2:";
	int b,temp;
    cin>>b;	
    cout<<"b:"<<b<<endl;
    for(int i=0;i<b;i++){
    	cin>>temp;
    	if(a[temp]==1){
    		cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	
	return 0;
}
