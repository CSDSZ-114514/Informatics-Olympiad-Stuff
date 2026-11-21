#include<bits/stdc++.h>
using namespace std;
int w,n,s,buc[605],t,su;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	cin>>n>>w;
	for(int i=1;i<=n;i++){
		cin>>t;
		buc[t]++;
		t=600;
		su=0;
		s=max(i*w/100,1);
		while(t>=0){
			su+=buc[t];
			if(su>=s) {
				cout<<t<<" ";
				break;
			}
			t--;
		}
	}
}
