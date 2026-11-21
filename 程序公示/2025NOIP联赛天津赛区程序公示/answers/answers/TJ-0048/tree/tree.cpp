#include<bits/stdc++.h>
using namespace std;

const int N=8005;
int n,m;
int c[N];
int ans;

struct node{
	int cnt;
	int minn;
	vector<int>s;
}a[N];

void dfs(int x,int fa){
	if(a[x].cnt==0){
		c[x]=a[fa].minn;
		a[fa].minn++;
		return ;
	}
	for(int v:a[x].s){
		dfs(v,x);
	}
	int maxn=0;
	for(int v:a[x].s){
		maxn=max(maxn,c[v]);
	}
	bool flag=false;
	for(int v:a[x].s){
		if(a[v].cnt!=0) {
			flag=true;
		}
	}
	if(flag==true){
		for(int v:a[x].s){
			if(a[v].cnt==0) {
				maxn++;
				c[v]=maxn;
			}
		}
	}
	for(int v:a[x].s){
		c[x]=max(c[x],c[v]);
	}
	c[x]++;
	return ;
}

int idx[N];
int cnt_id;

void dfs2(int x){
	for(int v:a[x].s){
		idx[++cnt_id]=v;
		dfs2(v);
	}
	return ;
}

bool b[N];
int res;
int solve(int x){
	cnt_id=0;
	dfs2(x);
	for(int i=0;i<=n+1;i++) b[i]=false;
	b[c[x]]=true;
	for(int i=1;i<=cnt_id;i++){
		b[c[idx[i]]]=true;
	}
	for(int i=0;i<=n+1;i++) {
		if(b[i]==false) return i;
	}
}

void dfs3(int x){
	if(x==n+1){
		int res22=0;
		for(int i=1;i<=n;i++) {
			res22+=solve(i);
		}
		ans=max(ans,res22);
		return ;
	}
	for(int i=0;i<=n;i++) {
		c[x]=i;
		dfs3(x+1);
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			c[i]=-1;
			a[i].cnt=0;
			a[i].minn=0;
			a[i].s.clear();
		}
		int x;
		for(int i=2;i<=n;i++) {
			cin>>x;
			a[x].s.push_back(i);
			a[x].cnt++;
		}
		dfs3(1);
		
		cout<<ans<<endl;
	}
	return 0;
}
