#include<bits/stdc++.h>
using namespace std;
long long n,k,x[25];int a[10000005],ans;
void soe(){
	a[0]=1;
	a[1]=1;
	for(int i=2;i<=10000000;i++){
		if(a[i]==0){
			for(int j=2;i*j<=10000000;j++){
				a[i*j]=1;
			}
		}
	}
}
bool sus(int g){
	return !a[g];
}
void dg(int c,int sum,int b){
	if(c>k){
		if(sus(sum)){
			ans++;
		}
		return ;
	}
	for(int i=b+1;i<=n;i++){	
		dg(c+1,sum+x[i],i);
	}	
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	soe();
	dg(1,0,0);
	cout<<ans;
}
