#include <bits/stdc++.h>
using namespace std;
const int inf=1e9;
int t,febn[100005],temp,nu=2,ans[10005],ansn;
void feb(){
	febn[1]=1;
	febn[2]=2;
	while(febn[nu]<=1e9){
		nu++;
		febn[nu]=febn[nu-1]+febn[nu-2];
	}
}
int main(){
	cin>>t;
	feb();
//	for(int i=1;i<=nu;i++){
//		cout<<febn[i]<<" ";
//	}
	for(int i=1;i<=t;i++){
		cin>>temp;
		int las=temp;
		cout<<temp<<"=";
		ansn=0;
		for(int j=nu;j>=1;j--){
			if(las>=febn[j]){
				las=las-febn[j];
				ans[++ansn]=febn[j];
			}
			
		}
		for(int k=ansn;k>=1;k--){
			if(k==1){
				cout<<ans[k]<<endl;
			}else{
				cout<<ans[k]<<"+";
			}
		}
	}

	return 0;
}
