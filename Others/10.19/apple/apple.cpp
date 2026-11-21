#include<bits/stdc++.h>
using namespace std;
long long n,ans1,ans2;bool isok2=false;

int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
	cin>>n;
	while(n>0){
		ans1++;
		//cout<<n;
		if(n%3==1&&!isok2){
			ans2=ans1;
			isok2=true;
		}
		n-=ceil(1.0*n/3);
	}
	cout<<ans1<<" "<<ans2;
    return 0;
}