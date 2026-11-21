#include<bits/stdc++.h>
using namespace std;
long long n,rd[10005];
vector<int> ed[10005];
queue<int> q;
void tp(){
	for(int i=1;i<=n;i++){
		if(rd[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int t:ed[u]){
			rd[t]--;
			if(rd[t]==0){
				q.push(t);
			}
		}
		cout<<u<<" ";
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		int w=999;
		while(true){
			cin>>w;
			if(w==0){
				break;
			}
			ed[i].push_back(w);
			rd[w]++;
		}
	}
	tp();
	
}
