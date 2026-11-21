#include<bits/stdc++.h>
using namespace std;
long long n,m,l[2000005],r[2000005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x>0){
            r[x]=1;
        }else if(x==0){
            r[x]=1;
            l[x]=1;
        }else{
            l[-x]=1;
        }
	}
	for(int i=1;i<=1e6;i++){
        l[i]=l[i]+l[i-1];
        r[i]=r[i]+r[i-1];
    }
    // for(int i=1;i<=4;i++){
    //     cout<<l[i];
    // }
    // for(int i=1;i<=4;i++){
    //     cout<<r[i];
    // }
    long long ans=0;
	for(int i=1;i<=m;i++){
        long long aos=2*i;
	    if(aos>m){
	        ans=max(ans,r[i]+l[0]);
		    ans=max(ans,l[i]+l[0]);
	    }
	    else{
	        ans=max(ans,r[i]+l[m-aos]);
		    ans=max(ans,l[i]+r[m-aos]);
	    }
	}
	cout<<ans-r[0];
	return 0;
}
