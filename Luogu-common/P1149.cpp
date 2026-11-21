#include<bits/stdc++.h>
using namespace std;
long long n;long long s[15]={6,2,5,5,4,5,6,3,7,6},ans;

int main(){
	cin>>n;
	

	n-=4;
	for(int i=0;i<=1000;i++){
		for(int j=0;j<=1000;j++){
			int as=0,bs=0,cs=0;
			int sum=i+j,ti=i,tj=j;
			if(ti==0){
				as=6;
			}
			if(tj==0){
				bs=6;
			}
			if(sum==0){
				cs=6;
			}
			//cout<<"1:"<<as<<bs<<cs;
			while(ti!=0){
				as+=s[ti%10];
				ti/=10;
			}
			while(tj!=0){
				bs+=s[tj%10];
				tj/=10;
			}
			while(sum!=0){
				cs+=s[sum%10];
				sum/=10;
			}
			//cout<<"2:"<<as<<bs<<cs;
			if(as+bs+cs==n){
				ans++;
			}
		}
	}
	cout<<ans;
}
