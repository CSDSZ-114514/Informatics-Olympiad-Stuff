#include <bits/stdc++.h>
using namespace std;

int const N=8010,M=810;
int t,n,m,res;
int son[N][N],fat[N],ss[N],v[N];
int tmp[N],idx;
bool isA[N][N];

int Mex(int x){
	idx=0;
	memset(tmp,0,sizeof(tmp));
	for (int i=1;i<=n;i++){
		if (isA[i][x]) tmp[++idx]=v[i];
	}
	//for (int i=1;i<=idx;i++) printf("%d ",tmp[i]);
	bool f;
	for (int i=0;i<=n;i++){
		f=0;
		for (int j=1;j<=idx;j++){
			//printf("%d,%d ",tmp[j],i);
			if (tmp[j]==i){
				f=1;
				break;
			}
		}
		//printf("\n");
		if (!f) return i;
	}
//	sort(tmp+1,tmp+idx+1);
//	int cnt=0;
//	for (int i=1;i<=idx;i++){
//		if (tmp[i]!=cnt){
//			if (cnt==0) return 0;
//			if (++cnt!=tmp[i]) return cnt;
//		}
//	}
	return idx;
}

void init(int x){
	isA[x][x]=1;
	for (int i=1;i<=ss[x];i++){
		isA[son[x][i]][x]=1;
		init(son[x][i]);
	}
	if (x==1) return;
	for (int i=1;i<=n;i++) if (isA[i][x]) isA[i][fat[x]]=1;
	return;
}

void calc(){
	int cnt=0;
	for (int i=1;i<=n;i++){
		//printf("%d ",cnt);
		cnt+=Mex(i);
	}
	//printf("\n");
	res=max(res,cnt);
//	if (cnt==10){
//		for (int i=1;i<=n;i++) printf("%d,%d ",v[i],Mex(i));
//		printf("\n");
//	}
	return;
}

void solve1(int x){
	if (x>n){
		//for (int i=1;i<=n;i++) printf("%d ",v[i]);
		calc();
		return;
	}
	for (int i=0;i<n;i++){
		v[x]=i;
		solve1(x+1);
	}
	return;
}

void solve2(){
} 

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	
	int a;
	scanf("%d",&t);
	for (int x=1;x<=t;x++){
		memset(ss,0,sizeof(ss));
		memset(isA,0,sizeof(isA));
		scanf("%d %d",&n,&m);
		for (int i=1;i<n;i++){
			scanf("%d",&a);
			son[a][++ss[a]]=i+1,fat[i]=a;
		}
		init(1);
//		v[3]=1,v[2]=2;
//		printf("%d\n",Mex(2));
		for (int i=1;i<=n;i++){
			for (int j=1;j<=n;j++){
				printf("%d ",isA[j][i]);
			}
			printf("\n");
		}
		solve1(1);
		printf("%d\n",res);
	}
	
	return 0;
} 
