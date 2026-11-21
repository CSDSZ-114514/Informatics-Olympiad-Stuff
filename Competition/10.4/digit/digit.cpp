#include<bits/stdc++.h>
using namespace std;
map<long long,bool> f;
int main(){
	freopen("digit.in","r",stdin);
	freopen("digit.out","w",stdout);
	cin.tie(0);
	ios::sync_with_stdio(false);
	f[0]=false;
	for(int i=1;i<=1e6+5;i++){
		long long temp=i;
		set<long long> s;
		s.clear();
		
		while(temp){//cout<<1;
			if(temp%10)s.insert(temp%10);
			temp=temp/10;
		}
		auto mxit=s.end();
		auto mnit=s.begin();
		mxit--;
//		if(i<100){
//			cout<<*mxit<<" "<<*mnit<<endl;
//		}
//		
		//cout<<*mxit;
		long long flag=false;
		if(!f[i-*mxit])flag=true;
		if(!f[i-*mnit])flag=true;
		f[i]=flag;
	}
	
	long long g;cin>>g;
	for(int i=1;i<=g;i++){
		long long n;
		cin>>n;
		cout<<(f[n]?"YES":"NO")<<'\n';
	}
	
	return 0;
} 
