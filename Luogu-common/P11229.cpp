#include<bits/stdc++.h>
using namespace std;
long long T,n;
long long uses[15]={6,2,5,5,4,5,6,3,7,6};
long long s[10],ans;
void dg(int u,int vs,int yuanlai){
	if(vs==0){
		if(u==0){
			//cout<<s[3];
			long long sum=s[3]*100+s[2]*10+s[1]*1;
			//cout<<sum<<endl;
			ans=min(ans,sum);
		}else{
			return;
		}
	}else{
		for(int i=0;i<=9;i++){
			if(vs==yuanlai&&i==0){
				continue;
			}
			if(u>=uses[i]){
				s[vs]=i;
				dg(u-uses[i],vs-1,yuanlai);
			}
		}
	}
}
int main(){
	cin>>T;
	long long nt=0;
	while(T--){
		
		//nt++;
		//n=nt;
		cin>>n;
		if(n<=1){
			cout<<-1<<endl;
			continue;
		}else if(n%7==0){
			for(int i=1;i<=(n/7);i++){
				cout<<8;
			}cout<<endl;
			continue;
		}//else if(n==6){
		//	cout<<0<<endl;
		//	continue;
		//}
		else if(n%7==3&&n!=10&&n!=3){
			cout<<200;
			//long long eightnum=max(n/7-1,(long long)0);
			for(int i=1;i<=n/7-2;i++)cout<<8;
			cout<<endl;
			continue;
		}else{
			long long eightnum=max(n/7-1,(long long)0);
			//cout<<eightnum;
			n-=(eightnum*7);
			long long ans1=1e9;
			ans=1e9;
			memset(s,0,sizeof(s));
			dg(n,1,1);memset(s,0,sizeof(s));ans1=min(ans1,ans);ans=1e9;
			dg(n,2,2);memset(s,0,sizeof(s));ans1=min(ans1,ans);ans=1e9;
			dg(n,3,3);memset(s,0,sizeof(s));ans1=min(ans1,ans);ans=1e9;
			cout<<ans1;
			for(int i=1;i<=eightnum;i++){
				cout<<8;
			}
			cout<<endl;
			continue;
		}
	}	
	//dg(10,1,1);
	//cout<<ans;
	//dg(10,2,2);
	//cout<<ans;
	//dg(10,3,3);
	//cout<<ans;
}
