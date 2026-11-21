#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
class node{
	node* fa;
	vector<node*> ch;
	int id,d,dp,sum,size;
	bool forup;
public:
	node(){dp=sum=id=d=size=0,fa=nullptr,ch=vector<node*>();}
	node(int Id,int D,node* F){dp=sum=size=0,id=Id,d=D,fa=F,ch=vector<node*>();};
	~node(){
		for(node* v:ch)v->~node();
	}
	node* add(int Id){
		node *tmp=new node(Id,d+1,this);
		ch.push_back(tmp);
		return tmp;
	}
	void dfs(){
		size=1;
		bool f=0;
		node *mx=new node;
		for(node *v:ch){
			v->dfs();
			size+=v->size;
			if(v->dp>=mx->dp)mx=v;
			if(v->dp>=v->size)
				dp+=v->dp+1,sum+=v->sum,f=1;
			else
				dp+=v->size;
		}
		if(!f&&mx->id!=0){
			dp-=mx->size;
			dp+=mx->dp+1;
			sum+=mx->sum;
			f=1;
		}
		sum+=dp+1;
		clog<<id<<" "<<size<<" "<<dp<<" "<<sum<<endl;
	}
	int getans(){
		return sum;
	}
};
node* g[8005];
void solve(){
	cin>>n>>m;
	g[1]=new node(1,0,nullptr);
	for(int i=2;i<=n;i++){
		int fa;
		cin>>fa;
		g[i]=g[fa]->add(i);
	}
	g[1]->dfs();
	cout<<g[1]->getans()<<endl;
}
void clear(){
	g[1]->~node();
	for(int i=1;i<=n;i++)g[i]=nullptr;
	n=m=0;
}
signed main(){
	freopen("tree2.in","r",stdin);
	freopen("tree2.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--){
		solve();
		clear();
		clog<<endl;
	}
	return 0;
}

