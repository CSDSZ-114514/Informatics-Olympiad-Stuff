#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define pre(i,a,b) for(int i=b;i>=a;i--)
using namespace std;
typedef long long ll;
const ll N=1e6+5;
ll n,m,a[N];
int main(){
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);
	cin>>n;
	rep(i,1,n){
		cin>>a[i];
	}
	cin>>m;
	rep(i,1,m){
		int l,r;
		cin>>l>>r;
		int sum=0;
		rep(i,l,r){
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
} 
