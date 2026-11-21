#include<bits/stdc++.h>
using namespace std;
long long n,m;
string w[3005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];sort(w[i].begin(),w[i].end());
	}
	for(int i=1;i<=n;i++){
		bool fl=true;
		for(int j=1;j<=n;j++){
			if(i!=j){
				if(w[i][0]>=w[j][m-1]){
					cout<<0;
					fl=false;
					break;
				}
			}
		}
		if(fl){
			cout<<1;
			
		}
	}
	
	return 0;
}
