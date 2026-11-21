#include<bits/stdc++.h>
//#define int long long
#define pb emplace_back
#define fi first
#define se second
#define mkp make_pair
#define il inline
typedef long long ll;
using namespace std;
using pii=pair<int,int>;
template<typename T> T& read(T& s){
	s=0;char c;
	do c=getchar();while(!isdigit(c));
	while(isdigit(c))s=(s<<1)+(s<<3)+(c^48),c=getchar();
	return s;
}
template<typename T> void write(T x){
	if(!x)return putchar(48),void();
	static int St[40],Top;
	if(x<0)putchar('-'),x=-x;
	while(x)St[++Top]=x%10,x/=10;
	while(Top)putchar(St[Top--]^48);
}
template<typename type,typename ...T> void read(type &x,T& ...y){read(x),read(y...);}
const int N=1e5+5;
int n;ll mm;
pii a[N];
ll work1(){
	ll m=mm;
	sort(a+1,a+n+1,[](pii x,pii y){return x.fi+x.se<y.fi+y.se;});
	int x=a[1].fi+a[1].se;
	ll ans=(m/x)*2;m%=x;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=n;i++)q.push(a[i]);
	while(m>0){
		pii to=q.top();q.pop();
		if(m<to.fi)break;
		ans++;m-=to.fi;swap(to.fi,to.se);q.push(to);
	}
	return ans;
}
ll work2(){
	ll ans=0,m=mm;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=n;i++)q.push(a[i]);
	while(m>0){
		pii to=q.top();q.pop();
		if(m<to.fi)break;
		pii nxt=q.top();
		if(to.se<nxt.fi||(to.se==nxt.fi&&to.fi<=nxt.se)){
			int x=to.fi+to.se;
			ans+=(m/x)*2;m%=x;
			if(m>=to.fi)ans++;
			break;
		}
		ans++;m-=to.fi;swap(to.fi,to.se);q.push(to);
	}
	return ans;
}
ll work3(){
	ll m=mm;
	sort(a+1,a+n+1,[](pii x,pii y){return x.fi+x.se<y.fi+y.se;});
	int x=a[1].fi+a[1].se;
//	cout<<a[1].fi<<" "<<a[1].se<<" "<<x<<endl;
	sort(a+1,a+n+1);
	ll ans=0;int pos=0;
//	for(int i=1;i<=30;i++)cout<<a[i].fi<<" "<<a[i].se<<endl;
	for(int i=1;i<=n;i++){
		if(a[i].fi*2>=x)break;
		pos=i;ans++;m-=a[i].fi;swap(a[i].fi,a[i].se);
	}
//	cout<<ans<<" "<<m<<endl;
	ans+=(m/x)*2;m%=x;
//	cout<<ans<<" "<<m<<endl;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	for(int i=1;i<=n;i++)q.push(a[i]);
//	cout<<endl;
	while(m>0){
		pii to=q.top();q.pop();
//		cout<<m<<" "<<to.fi<<endl;
		if(m<to.fi)break;
		ans++;m-=to.fi;swap(to.fi,to.se);q.push(to);
	}
	if(pos&&a[pos].se+m>=x)return ans+1;
	return ans;
}
il void solve(){
	read(n,mm);bool flag=1;ll m=mm;
	for(int i=1;i<=n;i++)read(a[i].fi,a[i].se);
	if(n==1){
		int x=a[1].fi+a[1].se;
		ll ans=(m/x)*2;m%=x;
		if(m>=a[1].fi)ans++;
		return write(ans);
	}
	for(int i=1;i<=n;i++)if(a[i].fi!=a[i].se){flag=0;break;}
	if(flag){
		sort(a+1,a+n+1);
		return write(m/a[1].fi);
	}
	write(work3());
}
signed main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int T=1;
	//read(T);
	while(T--){
		solve();
	}
	return 0;
}

