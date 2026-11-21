#include<bits/stdc++.h>
using namespace std;
long long n,m,s,t,t0,t1[10005],rq[10005];
long long cd[10005],rd[10005];
struct node{
	long long v,w;
};
vector<node> ed[10005];queue<int> q;
void tp(){
	q.push(s);rq[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(node t:ed[u]){
			int v=t.v,w=t.w;
			rq[v]+=(rq[u]%10000);
			t1[v]+=((rq[u]*w%10000+t1[u]%10000)%10000);
			rd[v]--; 
			if(rd[v] == 0){
				q.push(v);
			}
		}
	}
}
int main(){
	cin>>n>>m>>s>>t>>t0;
	for(int i=1;i<=m;i++){
		int a,b,c;
		cin>>a>>b>>c;
		ed[a].push_back({b,c});
		rd[b]++;cd[a]++;
	}
	tp();
	cout<<(t1[t]%10000+t0*(rq[t]-1)%10000)%10000;
	
	return 0;
}
