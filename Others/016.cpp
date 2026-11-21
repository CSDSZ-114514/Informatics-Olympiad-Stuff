#include<bits/stdc++.h>
using namespace std;
int d[10000005],n,l,r,temp,maxr,num1,num2,ans1,ans2,minl=1e9,lt;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l>>r;
		maxr=max(maxr,r);
		minl=min(minl,l);
		d[l]++;
		d[r]--;
	}
	for(int i=minl;i<maxr;i++){
		temp=d[i]+lt;
		//cout<<i<<" "<<temp<<endl;
		if(temp==0){
			num2=0;
			num1++;
			ans1=max(num1,ans1);
		}else{
			num1=0;
			num2++;
			ans2=max(num2,ans2);
		}
		lt=temp;
	}
	cout<<ans2<<" "<<ans1;
}
