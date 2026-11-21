#include<fstream>
#include<algorithm>
#include<cmath>
using namespace std;
long long w[100000],v[100000];
ifstream cin("tree.in");
ofstream cout("tree.out");
struct node{
	long long i
	;double rate;
}rate[100000];
void inc(long long n){
	/*if(a[n]==1){
		a[n]++;
		break;
	}else{*/
		for(long long i=n;i>0;i--){
			if(w[i]==2) w[i]--;
			else{
				w[i]++;
				break;
			}
		}
	//}
}
bool cmp(node a,node b){
	if(a.rate==b.rate){
		if(v[a.i]==v[b.i]){
			return a.i>b.i;
		}else return v[a.i]>v[b.i];
	}else return a.rate>b.rate;
}long long sdp(long long n,long long m){
	//set w,v
	//In:n,m
	long long dp[n+1][m+1];
	for(long long i=0;i<=m;i++) dp[0][i]=0;
	for(long long i=0;i<=n;i++) dp[i][0]=0;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=m;j++){
			if(j<w[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-w[i]]+v[i]);
		}
	}return dp[n][m];
}long long sR(long long n,long long m){
	for(long long i=1;i<=n;i++){
		rate[i].rate=(double)v[i]/(double)w[i];
		rate[i].i=i;
		//cout<<rate[i].i<<" "<<rate[i].rate<<endl;
	}sort(rate+1,rate+n+1,cmp);
	long long summ=0;
	for(long long i=1;i<=n;i++){
		if(m>=w[rate[i].i]){
			summ+=v[rate[i].i];
			m-=w[rate[i].i];
		}
	}return summ;
}long long solve(long long n,long long m){
	long long summ=0;
	for(long long i=1;i<=pow(2,n);i++){
		if(sdp(n,m)==sR(n,m)) summ++;
		inc(n);
	}return summ;
}//end enter ques
int main(){
	long long c,T;
	cin>>c>>T;
	bool noip=false;
	for(long long t=0;t<T;t++){
		long long n,m;
		cin>>n>>m;
		for(long long i=1;i<=n;i++){
			cin>>v[i];
			w[i]=1;
		}if(noip) cout<<endl;
		else noip=true;
		cout<<solve(n,m);
	}cin.close();cout.close();
	return 0;
}
