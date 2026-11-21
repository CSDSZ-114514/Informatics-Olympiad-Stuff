#include<bits/stdc++.h>
using namespace std;
int n,tmsum;
struct ST{
	int s=0,t=0;
}st[1005];
bool cmp(ST x,ST y){
	return x.s<y.s;
}
bool check(int t){
	int ntm=t;
	for(int i=1;i<=n;i++){
		if(ntm+st[i].t>st[i].s){
			return false;
		}else{
			ntm+=st[i].t;
		}
	}
	return true;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>st[i].t>>st[i].s;tmsum+=st[i].t;
	}
	sort(st+1,st+1+n,cmp);
	//cout<<st[1].s;
	int l=0,r=tmsum,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		//cout<<mid;
		if(check(mid)){
			l=mid+1;ans=mid;
		}else{
			r=mid-1;
		}
	}
	if(ans==0){
		cout<<-1;
	}else{
		cout<<ans;
	}
	return 0;
}
