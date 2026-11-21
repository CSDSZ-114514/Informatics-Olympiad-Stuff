#include<bits/stdc++.h>
using namespace std;
long long n,porm[15][15],corm,ans,te,Y,Z;
bool check(long long k,int nu){
	long long pm[6]={0,0,0,0,0,0},b=5;
	while(k!=0){
		pm[b--]=k%10;
		k/=10;
	}
//	for(int i=1;i<=5;i++){
//		cout<<pm[i];
//	}cout<<endl;
	b=0;bool pc=false;
	for(int i=1;i<=5;i++){
		if(pm[i]!=porm[nu][i]){
			b++;
			if((pm[i]-porm[nu][i]+10)%10==(pm[i-1]-porm[nu][i-1]+10)%10){
				pc=true;
			}
		}
	}
	if(b==1){
		//cout<<"1:"<<k<<endl;
		Z++;return 1;
	}else if(b==2&&pc){
		Y++;return 1;
	}else{
		return 0;
	}
}
int main(){
            freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=5;j++){
			cin>>porm[i][j];
		}
	}
	for(int i=0;i<=99999;i++){
		bool fl=true;
		for(int j=1;j<=n;j++){
			if(!check(i,j)){
				fl=false;
			}
		} 	
		if(fl){
			ans++;
		}
	}//cout<<Y<<endl<<Z<<endl;
	
	cout<< ans<<endl;
	return 0;
}