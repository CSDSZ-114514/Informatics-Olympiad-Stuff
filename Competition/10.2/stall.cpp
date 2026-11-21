#include<bits/stdc++.h>
using namespace std;
long long n,pd[1000005];
struct SD{
	long long s,t;
}s[10000005];
struct NP{
	long long t,n;
	bool operator<(const NP x) const{
		return t > x.t; 
	} 
};
bool cmp(SD x,SD y){
	return x.s<y.s;
}
priority_queue<NP> q;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].s>>s[i].t;
	}
	sort(s+1,s+1+n,cmp);
	long long idx=0;
	for(int i=1;i<=n;i++){
		//if(!q.empty())cout<<q.top().t<<endl;
		if(!q.empty()&&q.top().t<s[i].s){
			pd[i]=q.top().n;
			q.push({s[i].t,q.top().n});
			q.pop();
		}else{
			pd[i]=++idx;
			q.push({s[i].t,idx});
		}
	}
	cout<<idx<<endl;
	for(int i=1;i<=n;i++)cout<<pd[i]<<endl;
	return 0;
}
