#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,summ,cnt,an[100005];
int flag[100005];
struct node{
	long long x,y,sum;
}a[100005];
bool cmp(node aa,node bb){
	if(aa.sum==bb.sum){
		return aa.x>bb.x;
	}
	else{
		return aa.sum<bb.sum;
	}
}
bool cmp1(node aaa,node bbb){
	return aaa.x<bbb.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld",&a[i].x,&a[i].y);
		a[i].sum=a[i].x+a[i].y;
	}
	sort(a+1,a+n+1,cmp);
	sort(a+2,a+n+1,cmp1);
	ans=0,summ=0;
//	for(int i=1;i<=n;i++){
//		cout<<a[i].x<<" "<<a[i].y<<" "<<a[i].sum<<"\n";
//	}
	for(int i=2;i<=n;i++){
		if(a[i].x<=a[1].y&&a[i].x<=a[1].x&&summ+a[i].x<=m){
			summ+=a[i].x;
			flag[i]=1;
			a[i].x=1e9+7;
			ans++;
			an[++cnt]=i;
		}
	}
	sort(a+2,a+n+1,cmp1);
	long long c=m-summ;
	long long dd=(c/a[1].sum*2);
	if(a[1].x>=a[1].y){
		for(int i=2;i<=n;i++){
			if(a[i].x+a[i+1].x<=a[1].sum&&summ+a[i].x+a[i+1].x<=m){
				ans+=2;
				summ+=(a[i].x+a[i+1].x);
				a[i].x=1e9+7;
				a[i+1].x=1e9+7;
				i++;
			}
		}
		c=m-summ;
		dd=(c/a[1].sum*2);
		ans+=dd;
		summ+=(dd/2*a[1].sum);
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n;i++){
			if(summ+a[i].x<=m){
				summ+=a[i].x;
				ans++;
			}
		}
		printf("%lld\n",ans);
	}
	else{
		if(dd<2){
			sort(a+1,a+n+1,cmp1);
			for(int i=1;i<=n;i++){
				if(summ+a[i].x<=m){
					summ+=a[i].x;
					ans++;
				}
			}
			printf("%lld\n",ans);
		}
		else{
			ans+=dd;
			summ+=(dd/2*a[1].sum);
			if(summ+a[1].x<=m){
				ans++;
				summ+=a[1].x;
			}
			sort(a+2,a+n+1,cmp1);
			for(int i=2;i<=n;i++){
				if(a[i].x<=a[1].y&&summ+a[i].x<=m){
					ans++;
					summ+=a[i].x;
				}
			}
			if(summ+a[1].y<=m){
				ans++;
			}
			printf("%lld\n",ans);
		}
	}
//	for(int i=1;i<=cnt;i++){
//		cout<<an[i]<<" ";
//	}
//	cout<<"\n";
	return 0;
} 
