#include<bits/stdc++.h>
using namespace std;
long long n,d;long long c[100005],e[100005],minoi,minop=1e9,r,s;
int main(){
	cin>>n>>d;
	for(int i=1;i<n;i++){
		cin>>c[i];
	}
	for(int j=1;j<n;j++){
		cin>>e[j];
	}
	for(int i=1;i<n;i++){
		if(e[i]<minop){
			minop=e[i];
		}
		if(r<c[i]){
			s=(c[i]-r-1)/d+1;
			minoi+=minop*s;
			r=s*d+r-c[i];
		}else{
			r-=c[i];
		}
	}		
	cout<<minoi;
}
