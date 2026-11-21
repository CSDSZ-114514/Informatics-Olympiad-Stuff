#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int po(int x) {
	int su=1;
	for(int i=1; i<=x; i++) {
		su*=x;
	}
	return su;
}
vector<int>g[8009];
int cu[8009];
int sum=0;
vector<int> dfs(int x,int fa) {
   // cout<<x<<endl;
	vector<int>c,d;
	for(int i:g[x]) {
        if(i!=fa){
            d=dfs(i,x);
            for(int j:d){
                c.push_back(j);
            }
        }
	}
	c.push_back(cu[x]);
	c.push_back(1000);
	sort(c.begin(),c.end());
	int j=-1;
	for(int i:c){
        if(i>j+1){

               //cout<<"sls"<<' '<<j<<endl;
            sum+=j+1;
            break;
        }
        j=i;
	}
	return c;
}
int main() {
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
	int t;
	cin>>t;
	int n,m;
	int p[8009];
	int u;
	while(t--) {
		cin>>n>>m;
		for(int i=0;i<n;i++){
            g[i].clear();
		}
		for(int i=1; i<n; i++) {
			scanf("%d",&p[i]);
			p[i]--;
			g[p[i]].push_back(i);
		}
		int minn=0;
		for(int i=0; i<po(n); i++) {
                sum=0;
			u=i;
			for(int j=0; j<n; j++) {
				cu[j]=u%n;
				u/=n;
			}
			dfs(0,-1);
			minn=max(minn,sum);
			//cout<<i<<endl;
		}
		cout<<minn<<endl;
	}
	return 0;
}
