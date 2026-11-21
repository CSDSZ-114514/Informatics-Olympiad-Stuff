#include<bits/stdc++.h>
using namespace std;
struct candy{
	int x,y,w;
	bool operator <(const candy c) const {
		return c.w<w;
	}
};
long long n,m,minw=1e9+5,ans;
priority_queue<candy> q; 
int main() {
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		long long x,y;
		cin>>x>>y;
		minw=min(minw,x+y);
		q.push({x,y,x});
	}
	while(m>0) {
		candy a=q.top();
		q.pop();
		candy b=q.top();
		q.pop();
		//cout<<a.w<<' '<<b.w<<endl; 
		if(a.w==a.x) q.push({a.x,a.y,a.y});
		else q.push({a.x,a.y,a.x});
		if(b.w==b.x) q.push({b.x,b.y,b.y});
		else q.push({b.x,b.y,b.x});
		if(a.w+b.w>=minw) {
			//cout<<a.w<<' '<<b.w<<' '<<m<<endl;
			ans+=(m/minw)*2;
			m%=minw;
			if(m>=a.w) ans++;
			break;
		} else {
			m-=(a.w+b.w);
			ans+=2;
		}
	}
	//cout<<m<<' '<<minw<<endl;
	cout<<ans;
	return 0;
} 
