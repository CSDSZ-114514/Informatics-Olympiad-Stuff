#include<bits/stdc++.h>
using namespace std;
long long w,n;
const long long N=1e6+5;
struct ST{
	string s;long long id;
	bool operator<(const ST y)const{
		return s<y.s;
	}
}st[1000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>w>>n;
	for(int i=1;i<=w;i++){
		string s;cin>>s;
		st[i].s=s;st[i].id=i;
	}
	sort(st+1,st+1+w);
	//for(int i=1;i<=n;i++)cout<<st[i].s<<" ";
	for(int i=1;i<=n;i++){
		long long k;string s;
		cin>>k>>s;ST a={s,0},b={s+"{",0};
		long long fst=lower_bound(st+1,st+1+w,a)-st-1;
		long long lst=lower_bound(st+1,st+1+w,b)-st-1;
		long long len=lst-fst;
		if(k>len){
			cout<<-1<<'\n';
		}else{
			cout<<st[fst+k].id<<'\n';
		}
	}
	return 0;
}
