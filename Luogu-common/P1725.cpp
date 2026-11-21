#include<bits/stdc++.h>
using namespace std;
int a[2000005],n,l,r,f[2000005];
deque<int> q;
int main(){
	cin>>n>>l>>r;
//	#define int long long 
	memset(f,128,sizeof(f));
	f[0]=0;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	for(int i=l;i<=n+r;i++){
//		if(i-l<0){
//			continue;
//		}
		while(!q.empty()&&f[i-l]>f[q.back()]){
			q.pop_back();
		}
		q.push_back(i-l);
		if(q.front()<i-r){
			q.pop_front();
		}
		
		f[i]=f[q.front()]+a[i];
//		for(int j=i-r;j<=i-l;j++){
//			if(j>=0){
//				f[i]=max(f[j]+a[i],f[i]);
//			}
//		}
		
	}
	int ans=-1e9;
	for(int i=n;i<=n+r;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans;
	return 0;
}
