#include<bits/stdc++.h>
using namespace std;
int n,m,nnum[1000005],maxn,sumn;
bool pand(int in){
	int sum=0,num=1;
	for(int i=1;i<=n;i++){
		if(sum+nnum[i]>in){
			sum=0;
			num++;
		}
		sum+=nnum[i];
	}
	return num<=m;
}
int erfe(int l,int r){
	int ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		//cout<<mid<<" ";
		
		if(pand(mid)){
			ans=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nnum[i];
		maxn=max(maxn,nnum[i]);
		sumn+=nnum[i];
	}
	cout<<erfe(maxn,sumn);
}
