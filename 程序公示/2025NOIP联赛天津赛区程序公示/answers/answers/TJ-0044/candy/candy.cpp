#include<bits/stdc++.h> 
using namespace std;
int x[100005],y[100005],w[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	long long n,m,js=0;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>x[i]>>y[i];
		w[i]=x[i]+y[i];
	}
	long long t=0,k=w[0];
	for(long long i=1;i<n;i++){
		if(k>w[i]){
			k=w[i];
			t=i;
		}
	}
	sort(x,x+n);
	for(long long i=0;i<n;i++){
		if(2*x[i]<k&&i!=t){
			if((m-x[i])<0){
				cout<<js;
				return 0;
			}
			js++;
			m-=x[i];
			x[i]=y[i];
		}
	}
	while(m-k>=0){
	m-=k;
	js+=2;
}
sort(x,x+n);
	for(long long i=0;i<n;i++){
		if(x[i]<=m){
			js++;
			m-=x[i];
		}
	}

//	if(w[t]==x[t]) w[t]=y[t];
//	else w[t]=x[t];
	cout<<js;	
	return 0;
}
