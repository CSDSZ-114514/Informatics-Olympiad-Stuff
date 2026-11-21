#include<bits/stdc++.h>

using namespace std;
int n,pkd=0;
long long m;
struct node{
	long long x,y;
	long long z;
}l[100005];
bool cmp(node a,node b){
	if (a.z==b.z){
		if (a.x==b.x){
			return a.y<b.y;
		}else{
			return a.x<b.x;
		}
	}else{
		return a.z<b.z;
	}
}
long long sum=0,sum1=0;
struct candy{
	int xb,xy;
	long long s;
	bool operator<(const candy &v)const{
		return s>v.s;
	}
};
priority_queue<candy> q,q1;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&l[i].x,&l[i].y);
		if (l[i].x!=l[i].y)pkd=1;
		l[i].z=l[i].x+l[i].y;
	}
	sort(l+1,l+n+1,cmp);
	if (!pkd){
		long long sum=m/l[1].x;
		printf("%d",sum);
		return 0;
	}
	long long M=m,M1=m;
	for (int i=1;i<=n;i++){
		q.push({i,0,l[i].x});
	}
	q1.push({1,1,l[1].y});
	for (int i=2;i<=n;i++){
		q1.push({i,0,l[i].x});
	}
	sum=sum+((int)(M/l[1].z))*2,M=M%l[1].z;
	sum1=sum1+((int)(M1/l[1].z))*2-1,M1=M1%l[1].z+l[1].y;
	while (true){
		candy pd=q.top();
		if (pd.s<=M){
			M-=pd.s;
			sum++;
			q.pop();
			q.push({pd.xb,!pd.xy,pd.xy?l[pd.xb].x:l[pd.xb].y});
		}else{
			break;
		}
	}
	while (true){
		candy pd1=q1.top();
		if (pd1.s<=M1){
			M1-=pd1.s;
			sum1++;
			q1.pop();
			q1.push({pd1.xb,!pd1.xy,pd1.xy?l[pd1.xb].x:l[pd1.xb].y});
		}else{
			break;
		}
	}
	printf("%d",max(sum,sum1));
	fclose(stdin);
	fclose(stdout);
	return 0;
}
