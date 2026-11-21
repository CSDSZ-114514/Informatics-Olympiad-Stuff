#include<bits/stdc++.h>
using namespace std;
long long n,m,k,at[400005];
bool undes[400005];
vector<long long> e[400005];
long long fa[400005],ltk[400005];
long long find(long long x) {
    long long root = x;
    while (fa[root] != root) root = fa[root];
    while (fa[x] != x) {
        long long nxt = fa[x];
        fa[x] = root;
        x = nxt;
    }
    return root;
}
void heb(long long x,long long y) {
	fa[find(x)]=find(y);
} 
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		long long x,y;cin>>x>>y;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=0;i<n;i++){
		fa[i]=i;undes[i]=1;
	}
	cin>>k;
	for(int i=1;i<=k;i++){
		cin>>at[i];
		undes[at[i]]=0;
	} 
	for(int i=0;i<n;i++){
		if(undes[i]){
			ltk[k]++;
			for(long long t:e[i]){
				if(undes[t]){
					if(find(t)==find(i))continue;
					heb(i,t);
					ltk[k]--;
				}
			}
		}
	}
	for(int i=k;i>=1;i--){
		undes[at[i]]=true;
		ltk[i-1]=ltk[i];
		ltk[i-1]++;
		for(long long t:e[at[i]]){
			if(undes[t]){
				if(find(at[i])==find(t))continue;
				heb(at[i],t);
				ltk[i-1]--;
			}
		}
	}
	for(int i=0;i<=k;i++)cout<<ltk[i]<<endl;
	
	
	return 0;
} 
