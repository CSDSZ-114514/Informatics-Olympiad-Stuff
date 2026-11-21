#include<bits/stdc++.h>
using namespace std;
long long n,na,nb,naa[1005],nba[1005],a,b,sa,sb;
int g[5][5]={{0,0,1,1,0},{1,0,0,1,0},{0,1,0,0,1},{0,0,1,0,1},{1,1,0,0,0}};
int main(){
	cin>>n>>na>>nb;
	for(int i=1;i<=na;i++){
		cin>>naa[i];
	}
	for(int i=1;i<=nb;i++){
		cin>>nba[i];
	}
	for(int i=1;i<=n;i++){
		sa += g[naa[i % na]][nba[i % nb]]; 
		sb += g[nba[i % nb]][naa[i % na]];
	}
	cout<<sa<<" "<<sb;
}
