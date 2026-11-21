#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long p=(long long)1e9+7;
long long f[1000015],cf[1000015];
long long fa[2000005],l[2000005],r[2000005];
long long init(){
	cf[0]=1;
	for(int i=1;i<=1000005;i++){
		cf[i]=(cf[i-1]*i)%p;
	}
	for(int i=1; i<=n; i++) {
		fa[i]=i; 
	}
	return 1;
}
long long geta(long long cn,long long cm){
	return cf[cn]%p;
}
int find(int x) {
	if(x == fa[x]) {
		return x;
	} else {
		return fa[x] = find(fa[x]);
	}
}
void unionset(int x, int y) {
	fa[find(x)] = find(y);
} 
int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(0);cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		long long a,b;
		cin>>a>>b;
		if(r[a]==b&&l[b]==a){
			continue;
		}
		if(r[a]!=b&&r[a]!=0){
			cout<<0;return 0;
		}
		if(l[b]!=a&&l[b]!=0){
			cout<<0;return 0;
		}
		r[a]=b;l[b]=a;
		if(find(a)==find(b)){
			cout<<0;return 0;
		}
		unionset(a,b);
		n--;
	}
	cout<<geta(n,n);
	return 0;
}
