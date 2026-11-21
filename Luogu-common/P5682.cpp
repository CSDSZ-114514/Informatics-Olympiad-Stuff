#include<bits/stdc++.h>
using namespace std;
int n,a[1000005],buk[1000005],maxa;
bool cmp(int x,int y){
	return x>y;
}
void qvc(){
	for(int i=1;i<=n;i++){
		buk[a[i]]++;
	}
	memset(a,0,sizeof(a));
	n=0;
	for(int i=maxa;i>=1;i--){
		if(buk[i]!=0){
			a[++n]=i;
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(a[i],maxa);
	}
	sort(a+1,a+n+1,cmp);
	qvc();
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<" ";
//	}
	if(n==1){
		cout<<-1;
	}else if(n==2){
		cout<<a[1]%a[2];
	}else{
		cout<<max(a[3],a[1]%a[2])<<endl;
//		cout<<a[3]<<" "<<a[1]%a[2];
	}
}
