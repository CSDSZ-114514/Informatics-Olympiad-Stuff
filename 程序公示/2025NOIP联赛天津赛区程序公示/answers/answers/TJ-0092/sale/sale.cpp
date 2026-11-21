#include <bits/stdc++.h>
#define ll long long
#define MAXN 5010
#define M 998244353
using namespace std;
int c,t;
int n,m,res,w[MAXN];
ll max_num,sum;
struct node{
	int a,num;
	double w,xjb;
}candy[MAXN];
void init(){
	n=m=res=0;
	memset(candy,0,sizeof(candy));
	memset(w,0,sizeof(w));
}
void dfs(int pos,int cost,ll acost){
	max_num=max(max_num,acost);
	
	for(int i=pos+1;i<=n;i++){
		if(candy[i].w+1+cost<=m){
			dfs(i,cost+candy[i].w+1,acost+candy[i].a);
		}
	}
}
bool cmp(node a,node b){
	if(a.xjb!=b.xjb)return a.xjb>b.xjb;
	if(a.a!=b.a)return a.a>b.a;
	return a.num<b.num;
}
int main(){
	freopen("sale.in","r",stdin);
	freopen("sale.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		init();
		int ans=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&candy[i].a);
			candy[i].num=i;
		}
		for(int i=1;i<=1<<n;i++){
			w[1]++;
			for(int j=1;j<=n&&w[j]==2;j++){
				w[j]=0;
				w[j+1]++;
			}
			for(int j=1;j<=n;j++){
				candy[j].w=w[candy[j].num];
			}
			//max_num
			max_num=0;
			sum=0;
			dfs(0,0,0);
			//sum
			for(int j=1;j<=n;j++){
				candy[j].xjb=candy[j].a/(candy[j].w+1);
			}
			sort(candy+1,candy+1+n,cmp);
			int cost=0;
			for(int j=1;j<=n;j++){
				if(cost+candy[j].w+1<=m){
					cost+=candy[j].w+1;
					sum+=candy[j].a;
				}
			}
			//judge
			if(max_num==sum)ans++;
			ans%=M;
		}
		cout<<ans%M<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//0 1 3 2 1 3 5
//5 8

