#include<bits/stdc++.h>
using namespace std;
long long m,n,a[100005];string str;
long long f[100005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	cin>>m;
	cin>>str;
	if(m<3){
		cout<<0;return 0;
	}
	if(str[0]='a'&&str[1]=='b'&&str[2]=='c'){
		f[2]=a[1];
	}
//	for(int i=0;i<m;i++){
//		cout<<f[i];
//	}
	for(int i=3;i<m;i++){
		f[i]=f[i-1];
		for(int j=1;j<=n;j++){
			if(i-3*j+1>=0){
				
				if(str[i-3*j+1]=='a'&&str[i-3*j+2]=='b'&&str[i-3*j+3]=='c'){
					f[i]=max(f[i],f[i-3*j]+a[j]);
				}
				else break;
			}
			else break;
		}
	}
//	for(int i=0;i<`m;i++){
//		cout<<f[i];
//	}
	cout<<f[m-1];
	return 0;
}
