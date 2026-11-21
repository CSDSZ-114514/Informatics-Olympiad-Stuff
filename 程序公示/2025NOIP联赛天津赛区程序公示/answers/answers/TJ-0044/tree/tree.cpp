#include<bits/stdc++.h> 
using namespace std;
int p[8005],q[8005],z[8005],h[8005];//孩子数 父亲 层数 计数 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
int t;
cin>>t;
for(int k=0;k<t;k++){
	int n,m;
	cin>>n>>m;
	for(int j=2;j<=n;j++){
	cin>>q[j];	
	p[q[j]]++;
	}
	long long js=0;
	for(int i=n;i>=1;i--){
		if(p[i]==0) z[q[i]]=1;
		if(p[i]>0){
			if(z[i]==1){
			js++;
			h[i]=max(p[i],h[i]);
			}					
//			z[q[i]]=max(z[q[i]],z[i]);
			js+=(h[i]+1);
			h[q[i]]=max(h[q[i]],h[i]+1);
		}
	}
	cout<<js<<endl;
	for(int j=0;j<=n;j++){
	p[j]=0;
	q[j]=0;
	z[j]=0;
	h[j]=0;	
	}
/*for(int j=1;j<=n;j++){
	cout<<"名称"<<j<<endl;
	cout<<"孩子数"<<p[j]<<endl; 
	cout<<"父亲"<<q[j]<<endl;
	cout<<"层数"<<z[j]<<endl;
	cout<<"计数"<<h[j]<<endl;
}*/
}
return 0;
}
