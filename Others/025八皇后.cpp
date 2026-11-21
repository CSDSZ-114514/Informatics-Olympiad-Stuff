#include<bits/stdc++.h>
using namespace std;
int ys[10],n=8,no;
int pow2 (int a){
	if(a<=0){
		return -1;
	}else{
		return a;
	}
}
bool isok(int x,int y){
	for(int i=1;i<x;i++){
		if(ys[i]==y){
			return false;
		}
		if(i-ys[i]==x-y||i+ys[i]==x+y){
			return false;
		}
	}
	return true;
}
void dg(int x,int y){
	if(x==n+1){
		no++;cout<<"No. "<<no;
		for(int i=1;i<=n;i++){
			cout<<endl;
			for(int j=1;j<=n;j++){
				if(ys[i]==j){
					cout<<1<<" ";
				}else{
					cout<<0<<" ";
				}
				
			}
			
		}
		cout<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		if(isok(x,i)){
			ys[x]=i;
			dg(x+1,n);
		}
	}
}
int main(){
	dg(1,1);
	return 0;
}
