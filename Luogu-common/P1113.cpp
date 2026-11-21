#include<bits/stdc++.h>
using namespace std;
long long n,len[10005],rd[10005],f[10005],sum;
vector<int> v[10005];queue<int> q;
void tp(){
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			q.push(i);
			f[i]=len[i];
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		sum=max(sum,f[u]);
		for(int t:v[u]){
			rd[t]--;
			f[t]=max(f[u]+len[t],f[t]);
			if(rd[t]==0){
				q.push(t);
			}
		}
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int k=0;cin>>k;
		cin>>len[i];int w=999;
		while(true){
			cin>>w;
			if(w==0){
				break;
			}else{
				v[w].push_back(i);
				rd[i]++;
			}
		}
	}
	tp();cout<<sum;
	return 0;
}
