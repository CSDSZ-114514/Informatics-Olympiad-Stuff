#include<bits/stdc++.h>
using namespace std;
long long t;
long long n,m,ans;
vector<long long> e[105];
long long trn[105],prn[105];
bool cbd[55][55];
void dg2(long long fr,long long ffr){
	if(fr==1)return;
	cbd[prn[fr]][trn[ffr]]=1;
	dg2(prn[fr],ffr);
}
void dg(long long x){
	//递归真是太好用了你知道吗。
	//cout<<"kkkkkkkkkkkkkkk";
	if(x==n+1){
		memset(cbd,0,sizeof(cbd));
		//cout<<1;
		for(int i=1;i<=n;i++){
			cbd[i][trn[i]]=1;
			dg2(i,i);
		}
		long long tempans=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=n;j++){
				//cout<<cbd[i][j]<<" "; 
				if(cbd[i][j]==0){
					tempans+=j;
					break;
				}
			}
			//cout<<endl;
		}
		//cout<<endl;
//		if(tempans>ans){
//			for(int i=1;i<=n;i++){
//				for(int j=0;j<=n;j++){
//					cout<<cbd[i][j]<<" "; 
//				}
//				cout<<endl;
//			}
//			cout<<endl<<tempans<<endl;
//		}
		ans=max(ans,tempans);
		return ;
	} else{
		for(int i=0;i<=n;i++){
			trn[x]=i;
			dg(x+1);
		}
	}
}
void dgx(long long x){
	
}
int main(){ 
	//我对这道题有点思路了，但是我没时间写完它了。 
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>t;
	while(t--){
		ans=0;
		cin>>n>>m;
		for(int i=2;i<=n;i++){
			cin>>prn[i];
			e[prn[i]].push_back(i);
		}
		if(n<=30){
			dg(1);
		}else{
			dgx(1);
		}
		
		cout<<ans<<endl;
	}
	//NOIP2025 RP++!
	
	return 0;
}
