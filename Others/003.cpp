#include<bits/stdc++.h>
using namespace std;
int  a[1005][4],buc[1005],n,num;
void dg(int x){
	if(x==n+1){
		num++;
		return;
	}
	for(int i=1;i<=2;i++){
		if(buc[a[x][i]]==0){
			buc[a[x][i]]=1;
			dg(x+1);
			buc[a[x][i]]=0;
		}	
	}
	return;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
	}
	dg(1);
	cout<<num;

	return 0;
}
