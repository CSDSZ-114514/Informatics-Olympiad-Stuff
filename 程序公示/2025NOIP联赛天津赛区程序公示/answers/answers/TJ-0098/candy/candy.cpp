#include <bits/stdc++.h>
using namespace std;
struct Node{
	int a,b,z,id;
};
bool cmp1(Node x,Node y){
	if(x.z==y.z) return x.a<y.a;
	return x.z<y.z;
}
bool cmp2(Node x,Node y){
	return x.a<y.a;
}
Node node[100005];
long long m,ans;
int n,num;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>node[i].a>>node[i].b;
		node[i].z=node[i].a+node[i].b;
		if(node[i].a!=node[i].b) f=0;
		node[i].id=i;
	}
	if(f==1){
		sort(node+1,node+1+n,cmp2);
		ans=m/node[1].a;
		cout<<ans;
		return 0;
	}
	sort(node+1,node+1+n,cmp1);
	int sum1=node[1].z,sum2=node[1].a;
	int information=node[1].id,ans1=0;
	sort(node+1,node+1+n,cmp2);
	for(int i=1;i<=n;i++){
		if(node[i].id==information) continue;
		if(node[i].a<(sum1+1)/2){
			m-=node[i].a;
			ans1++;
			//cout<<node[i].a<<endl;
		}else if(node[i].a==(sum1+1)/2){
			num++;
		}else{
			break;
		}
	}
	//cout<<ans1<<endl;
	ans=m/sum1;
	m=m%sum1;
	ans=ans*2;
	//cout<<sum2<<endl;
	//cout<<sum1<<endl;
	if(num!=0&&m>=(sum1+1)/2){
		ans++;
		m=m-(sum1+1)/2;
	}
	if(sum2<=m) ans++;
	ans=ans+ans1;
	cout<<ans;
	return 0;
}
