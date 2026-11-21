#include<bits/stdc++.h>
using namespace std;
long long n,m,faceto[1000005],a,s,loc=0;
string niger[100005];
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>faceto[i]>>niger[i];
		
	}
	for(int i=1;i<=m;i++){
		cin>>a>>s;
		if(a==0){
			if(faceto[loc]==0){
				loc=loc-s;
			}else{
				loc=loc+s;
			}
		}else if(a==1){
			if(faceto[loc]==1){
				loc=loc-s;
			}else{
				loc=loc+s;
			}
		}
		loc=(loc+n)%n;
		//cout<<loc<<niger[loc]<<endl;
	}
	cout<<niger[loc];
}
