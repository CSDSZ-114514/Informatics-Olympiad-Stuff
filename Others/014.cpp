#include <bits/stdc++.h>
using namespace std;
int n,m;double len[10005],maxlen;
bool panduan(int lenpe){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=((int)len[i]/lenpe);
	}
	if(ans>=m){
		return true;
	}else{
		return false;
	}
}
int twofen(){
	int  left=1,right =10000000,ans=0;
	while(left<=right){
		int middle=(left+right)/2;
		if(panduan(middle)){
			ans=middle;
			left=middle+1;
		}else{
			right=middle-1;
		}
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>len[i];
		len[i]*=1000;
		maxlen=max(len[i],maxlen);
	}
	cout<<setprecision(2)<<fixed<<twofen()/(double)1000;
}
