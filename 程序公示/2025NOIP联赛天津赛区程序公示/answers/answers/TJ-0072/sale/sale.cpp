#include <iostream>
#include <algorithm>
#include <bitset>
#include <cstdio> 
using namespace std;
const int mod=998244353;
long long c,T;
long long n,m;
long long a[5010];
bitset<5010> b;//0 2     1 1
struct node{
	long long val;//xingjiabi
	long long id;//jiage
}w[5010];
bool cmp(node a,node b){
	return a.val>b.val;
}
long long ans=0;
long long cntt=99999999;
long long tmp;
void dfs(long long t){
	if(t>n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]==0){
				w[i].val=a[i];
				w[i].id=2;
			}else{
				w[i].val=a[i]*2;
				w[i].id=1;
			}
		}
		int now=m;
		sort(w+1,w+n+1,cmp);
		for(int i=1;i<=n;i++){
			if(now<w[i].id)break;
			if(w[i].id==w[i+1].id){
				int val1;int val2;
				if(w[i].id==1){
					val1=w[i].val/2;
				}else{
					val1=w[i].val;
				}
				if(w[i+1].id==1){
					val2=w[i+1].val/2; 
				}else{
					val2=w[i+1].val;
				}
				if(now>=w[i].id+w[i+1].id){
					now-=(w[i].id+w[i+1].id);
					cnt+=(val1+val2); 
				}else{
					now-=w[i].id;
					if(val1>val2){
						cnt+=val1;
					}else if(val1<val2){
						cnt+=val2;
					}else{
						cnt+=val1;
					}
					break;
				}
			}else{
				now-=w[i].id;
				if(w[i].id==1){
					cnt+=w[i].val/2;
				}else{
					cnt+=w[i].val; 
				}
			}
		}
		if(cnt>cntt){
			ans++;
		}else if(cnt==cntt){
			tmp++;
		}else{
			cntt=cnt;
			ans+=tmp;
			tmp=1;
		}
		return ;
	}
	b|=(1<<t);
	dfs(t+1);
	b[t]=0;
	dfs(t+1);
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)cin>>a[i];
		dfs(1);
		cout<<ans;
	}
	return 0;
}
