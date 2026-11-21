#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,T;
int m;
int c[100005][5];
bool vis[100005];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii> >q;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i][1]>>c[i][2];
		c[i][3]=c[i][1]+c[i][2];
	}
	int minn=LONG_LONG_MAX;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(minn>c[i][3])minn=c[i][3],ans=i;
	}
//	cout<<((m/minn)*2)+(m%minn)/c[ans][1];--->((m/minn)*2)+(m%minn)/c[ans][2]
	for(int i=1;i<=n;i++){
		if(c[i][1]*2<=minn){
			q.push(make_pair(c[i][1],i));
		}
	}
	int cnt=0;
	int maxn=0;
	while(q.size()){
		int j=q.top().first;
		int idx=q.top().second;
		q.pop();
//		cout<<j<<" ";
		if(m>=j){
			vis[idx]=1;
			m-=j;
			cnt++;
		}
		else{
			break;
		}
	}
//	cout<<c[ans][1]<<" "<<c[ans][2]<<" "<<m<<" ";
	if(c[ans][1]>=c[ans][2]){
		cnt+=(m/minn)*2;
		m=m%minn;
//		cout<<"\n";
//		cout<<m<<" ";
		for(int i=1;i<=n;i++){
			if(c[i][vis[i]+1]<=m){
				m-=c[i][vis[i]+1],cnt++;
//				cout<<c[i][1]<<" ";
			}
		}
		cout<<cnt;
		return 0;
	}
	else{
		cnt+=(m/minn)*2;
		m=m%minn;
		for(int i=1;i<=n;i++)if(c[i][1]<=m&&!vis[i])m-=c[i][1],cnt++;
		cout<<cnt;
		return 0;
	}
	return 0;
}
