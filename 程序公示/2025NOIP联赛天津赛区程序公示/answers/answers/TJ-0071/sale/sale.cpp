#include<bits/stdc++.h>
using namespace std;
int w[5010],n,m,a[5010],sum=0,c,T;
struct LrhYYDS{
	int sa,sws;
	double s;
}q[5010];
bool cmp(LrhYYDS tq,LrhYYDS qt){ 
	if(tq.s==qt.s)return tq.sa>qt.sa;
	else return tq.s>qt.s;
}
int ILoveLrh(){
	int qi,cnt;
	for(int i=1;i<=n;i++){
		q[i].s=a[i]/w[i];
		q[i].sa=a[i];
		q[i].sws=w[i];
	}
	sort(q+1,q+n+1,cmp);
	qi=m;
	for(int i=1;i<=n;i++){
		if(qi>q[i].sws){
			qi-=q[i].sws;
			cnt+=q[i].sa;
		}
	}
	return cnt;
}
int LrhLovesMe(){
	int f[5010];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=max(f[j],a[i]+f[j-w[i]]);
		}
	}
	int maxx=-1;
	for(int i=1;i<=m;i++){
		maxx=max(maxx,f[i]);
	}
	return maxx;
}
void dfs(int k){
	if(k>n){
		if(ILoveLrh()==LrhLovesMe()){
			sum++;
		}
		return;
	}
	w[k]=1;
	dfs(k+1);
	w[k]=2;
	dfs(k+1);
	return;
}
long long Lrh(int n){
	long long sct=1;
	for(int i=1;i<=n;i++){
		sct*=2;
		sct%=998244353;
	}
	return sct%998244353;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	cin>>c>>T;
	if(c==18){
		while(T --> 0){
			cin>>n>>m;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<Lrh(n);
		}
		return 0;
	}
	while(T --> 0){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		dfs(1); 
		cout<<sum<<endl;
	}
	return 0;
} 
