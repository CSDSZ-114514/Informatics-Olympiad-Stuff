#include<bits/stdc++.h>
using namespace std;
long long m,n,k,l,d;
//long long hg[100005],zg[100005];
struct hl{
	long long num,val;
}hg[100005],zg[100005];
bool cmp(hl x,hl y){
	return x.val>y.val;
}
long long ansh[100005],ansz[100005];
int main(){
	cin>>m>>n>>k>>l>>d;
	for(int i=1;i<=d;i++){
		long long x,y,p,q;
		cin>>x>>y>>p>>q;
		if(x==p)zg[min(y,q)].val++,zg[min(y,q)].num=min(y,q);
		if(y==q)hg[min(x,p)].val++,hg[min(x,p)].num=min(x,p);
	}
	sort(hg+1,hg+1+m-1,cmp);sort(zg+1,zg+1+n-1,cmp);
//	for(int i=1;i<=k;i++)cout<<hg[i].num<<" ";
//	cout<<endl;
//	for(int i=1;i<=l;i++)cout<<zg[i].num<<" ";
//	cout<<endl;
	for(int i=1;i<=k;i++){
		ansh[i]=hg[i].num;
	}
	for(int i=1;i<=l;i++){
		ansz[i]=zg[i].num;
	}
	sort(ansh+1,ansh+1+k);sort(ansz+1,ansz+1+l);
	for(int i=1;i<=k;i++)cout<<ansh[i]<<" ";
	cout<<endl;
	for(int i=1;i<=l;i++)cout<<ansz[i]<<" ";
}
