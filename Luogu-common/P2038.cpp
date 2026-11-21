#include<bits/stdc++.h>
using namespace std;
const int nsize = 128;
int d,n,p[130][130],t1,t2,sum,mxsu,mxnu=1;
int main(){
	cin>>d>>n;
	for(int i=1;i<=n;i++){
		cin>>t1>>t2>>p[t1][t2]; 
	}
	for(int i=0;i<=nsize;i++){
		for(int j=0;j<=nsize;j++){
			int sum = 0;
			for(int k=max(i-d,0);k<=min(i+d,128);k++){
				for(int b=max(j-d,0);b<=min(j+d,128);b++){
					sum+=p[k][b];
				}
			}
			if(mxsu==sum){
				mxnu++;
			}
			if(mxsu<sum){
				mxsu=sum;
				mxnu=1;
			}
			//cout<<mxnu<<" "<<mxsu<<endl;
		}	
	}
	cout<<mxnu<<" "<<mxsu;
}
