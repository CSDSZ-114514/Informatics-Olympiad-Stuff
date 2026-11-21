#include<bits/stdc++.h>
using namespace std;
long long n,p,st[10005],yu[10005];
long long cd[10005],rd[10005];
struct node{
	long long v,w;
};
vector<node> ed[10005];queue<int> q;
void tp(){
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		//
		//if(st[u]<=0) continue;
		for(node t:ed[u]){
			int v=t.v,w=t.w;
			if(st[u]>0){
				st[v]+=(w*st[u]);
			}
			rd[v]--;
			if(rd[v]==0){
				st[v]-=yu[v];
				q.push(v);
			}
		}
	}
}
int main(){
	cin>>n>>p;
	for(int i=1;i<=n;i++){
		cin>>st[i]>>yu[i];
	}
	for(int i=1;i<=p;i++){
		long long a,b,c;
		cin>>a>>b>>c;
		rd[b]++;cd[a]++;
		ed[a].push_back({b,c});
	}
	tp();bool fl=1;
	for(int i=1;i<=n;i++){
		if(cd[i]==0&&st[i]>0){
			fl=0;
			cout<<i<<" "<<st[i]<<endl;
		}
	}
	if(fl){
		cout<<"NULL"<<endl;
	}
}
