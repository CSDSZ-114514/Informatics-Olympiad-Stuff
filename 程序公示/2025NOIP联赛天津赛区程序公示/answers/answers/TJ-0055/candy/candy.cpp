#include<bits/stdc++.h>
using namespace std;
typedef struct cc{
	int xi;
	int yi;
	int sumi;
	int no;
	int nn;
}candy;//糖果价格 

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n,m,sum=0,min=0,minn=0,minx;
	cin>>n>>m;
	int mi=m;
	candy c[n];
	for(int i=0;i<n;i++){
		cin>>c[i].xi>>c[i].yi;
		c[i].sumi=c[i].xi+c[i].yi;
		c[i].no=i;
		if(c[i].sumi<min||min==0){
			min=c[i].sumi;
			minn=i;
			minx=c[i].xi;
		}
		}
	for(int i=1;i<n;i++){//给糖果排序 
		for(int j=0;j<n-1;j++){
			if(c[j].xi>c[j+1].xi){
				int nnn=c[j+1].xi,nnnn=c[j+1].sumi;
				c[j+1].xi=c[j].xi;
				c[j+1].sumi=c[j].sumi;
				c[j].xi=nnn;
				c[j].sumi=nnnn;
			}
		}
	}
	int i=0;
	while((c[i].xi+c[i+1].xi)<min&&i<n-1){
		m=m-c[i].xi-c[i+1].xi;
		sum=sum+2;
		i=i+2;
	}
	sum=sum+(m/min)*2;
	m=m%min;
	if(c[i].xi>minx&&c[minn].yi>c[i].xi){
		sum--;
		m=m+c[minn].yi;
	}
	while(m>=c[i].xi){
		m=m-c[i].xi;
		sum++;
		i++;
	}
	cout<<sum;	
	return 0;
}
