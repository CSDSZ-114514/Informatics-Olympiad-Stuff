#include<iostream>
using namespace std;
string str;
int ans,a[100000005],last;
int main(){
	freopen("gemstone.in","r",stdin);
	freopen("gemstone.out","w",stdout);
	cin>>str;
	last+=1e5;
	//a[100000]=0;
	for(int i=1;i<=str.length();i++){
		if(str[i-1]=='G'){
			last++;
		}else{
			last--;
		}
		if(!a[last]){
			a[last]=i;
		}else{
			//cout<<a[last]<<" ";
			ans=max(ans,i-a[last]);
		}
		if(last==1e5){
			ans=i;
		}
	}
	cout<<ans<<endl;
}
