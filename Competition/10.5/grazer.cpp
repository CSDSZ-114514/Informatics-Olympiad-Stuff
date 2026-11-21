#include<bits/stdc++.h>
using namespace std;
long long n,m;
struct MC{
	long long c,d;
	bool operator<(const MC p)const{
		return d>p.d;
	}
}mc[10000005];
struct CO{
	long long a,b;
	bool operator<(const CO p)const{
		return b>p.b;
	}
}co[10000005]; 
multiset<long long> s;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>co[i].a>>co[i].b;
	for(int i=1;i<=m;i++)cin>>mc[i].c>>mc[i].d;
	
	sort(mc+1,mc+1+m);
	sort(co+1,co+1+n);
	long long p=1,ans=0;//p:±È¿˙∂‡…Ÿmc
	 
	for(int i=1;i<=n;i++){
		while(p<=m&&mc[p].d>=co[i].b){
			s.insert(mc[p].c);
			++p;
		}
		//for(auto it:s)cout<<it<<" ";
		auto it=s.lower_bound(co[i].a);
		if(it==s.end()){
			cout<<-1;return 0;
		}
		ans+=*it;
		s.erase(it);
	}
	cout<<ans;
	return 0;
} 
