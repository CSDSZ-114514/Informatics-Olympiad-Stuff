#include<bits/stdc++.h>
using namespace std;
int n,a[100005],b[100000],bk=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(a[k]==a[i]+a[j]&&b[k]!=1){
					bk++;
					b[k]=1;
				}
			}
		}
	}
	cout<<bk;
	return 0;
}
