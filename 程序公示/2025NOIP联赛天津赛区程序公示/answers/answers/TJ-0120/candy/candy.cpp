#include<bits/stdc++.h>
#define int long long
using namespace std;
pair<int,int>a[500005];
bool vis[500005];
signed main() {
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int minn=1e18;
	for(int i=1; i<=n; i++) {
		cin>>a[i].first>>a[i].second;
		minn=min(minn,a[i].first+a[i].second);
	}
	sort(a+1,a+n+1);
	int now=0;
	int la=-10;
	int u=0;
	while(u>=la) {
	//	cout<<u<<" "<<la<<endl;
		int cnt=(m/minn)*2-now*2;
		int res=m%minn+minn*now;
//	cout<<cnt<<" "<<minn<<endl;
		priority_queue<pair<int,int> >q;
		int id=0;
		for(int i=1; i<=n; i++) {
			if(res>=a[i].first) {
				vis[i]=true;
				id=i;
				res-=a[i].first;
				q.push({a[i].first,i});
				cnt++;
			}
		}
		priority_queue<int>qq;
		for(int i=id+1; i<=n; i++) {
			if(q.size()&&a[i].first+a[i].second<=res+q.top().first&&a[i].first+a[i].second<=a[q.top().second].second+q.top().first) {
				res+=q.top().first;
				q.pop();
				qq.push(a[i].first+a[i].second);
				vis[i]=false;
				cnt++;
				res-=a[i].first+a[i].second;
			}
		}
		for(int i=1; i<=id; i++) {
			if(vis[i]) {
				if(res>=a[i].second) {
					res-=a[i].second;
					cnt++;
				}
			} else {
				if(res>=a[i].first) {
					res-=a[i].first;
					cnt++;
				}
			}
		}
//	cout<<res<<endl;
	//	cout<<cnt<<endl;
		la=u;
		u=cnt;
		now++;
	}
	cout<<la<<endl;
}
