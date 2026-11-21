#include<bits/stdc++.h>
using namespace std;
long long h,t;bool pri[100005];
long long ou(long long n){
	cout<<n;
	//n=1000005;
	pri[1]=1;pri[0]=0;
	for(int i=2;i<=n;i++){
		if(!pri[i]){
			cout<<"i:"<<i<<endl;
			for(int j=2;j<=n/i;j++){
				pri[i*j]=1;
				cout<<"j:"<<i*j<<endl;
				//cout<<1;
			}
		}
		cout<<endl;
	}
}
int main(){
	ou(5);
	
	cin>>t;
	while(t--){
		cin>>h;long long i=1;
		while(true){
			long long k=h-pow(2,i-1);
			if(k>0){
				if(!pri[k]){
					cout<<i<<endl;
					break;
				}else{
					h=k;
				}
			}else if(k==0){
				cout<<i<<endl;
				break;
			}else{
				cout<<-1<<endl;
				break;
			}
			i++;
		}
	}
	return 0;
}
