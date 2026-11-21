#include<bits/stdc++.h>
using namespace std;
long long n,t,isb[1000005],cnt=0;
vector<long long> v[100005];bool isok=true;
//vector<node> v[100005];
bool flag=true;
long long dg(long long dd,long long u){
	long long aq=0,tr=0;
	if(isb[u])aq+=1;
	for(long long t:v[u]){
		if(t!=dd){
			if(dg(u,t)){
				aq+=dg(u,t);tr++;
			}
		}
	}
	if(!((tr==2&&aq==cnt)||(tr==1))){
		isok=false;
	}
	return aq;
}
int main(){
	cin>>t;
	while(t--){
		isok=true;
		memset(isb,0,sizeof(isb));
		memset(v,0,sizeof(v));
		cin>>n;cnt=0;
		for(int i=1;i<=n;i++){
			cin>>isb[i];
			if(isb[i]){
				cnt++;
			}
		}
		for(int i=1;i<=n-1;i++){
			long long a,b;cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for(int i=1;i<=n;i++){
			if(isb[i]){
				dg(0,i);
				break;
			}
		}
		if(isok){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
