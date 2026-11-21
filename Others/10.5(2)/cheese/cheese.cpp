#include<bits/stdc++.h>
using namespace std;
long long n,num[100005];
double f[40][100005],dis[505][505];
struct NL{
	double x,y;
}nl[45];
int main(){
	cin>>n;
	memset(f,127,sizeof(f));
	for(int i=1;i<=n;i++){
		cin>>nl[i].x>>nl[i].y;
	}
	nl[0].x=0;nl[0].y=0;
	for(int i=0;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			dis[i][j]=sqrt((nl[i].x-nl[j].x)*(nl[i].x-nl[j].x)+(nl[i].y-nl[j].y)*(nl[i].y-nl[j].y));
			dis[j][i]=sqrt((nl[i].x-nl[j].x)*(nl[i].x-nl[j].x)+(nl[i].y-nl[j].y)*(nl[i].y-nl[j].y));
		}
	}
	for(int i=1;i<=n;i++){
		f[i][1<<(i-1)]=dis[0][i];
		//cout<<dis[0][i]<<" ";
	}
	for(int k=1;k<(1<<n);k++){
		//cout<<k<<" ";
		for(int i=1;i<=n;i++){
			if(((1<<(i-1))&k)==0)continue;
			for(int j=1;j<=n;j++){
				if(((1<<(j-1))&k)==0)continue;
				if(i==j)continue;
				f[i][k]=min(f[i][k],f[j][k-(1<<(i-1))]+dis[i][j]);
			}
		}
	}
	double minn=1e18;
	for(int i=1;i<=n;i++){
		//cout<<f[i][1<<n-1]<<endl;
		minn=min(minn,f[i][(1<<n)-1]);	
	}
	//5 1 3 5 7 2 4 6 8 9 0 18.78
	cout<<fixed<<setprecision(2)<<minn;
}
