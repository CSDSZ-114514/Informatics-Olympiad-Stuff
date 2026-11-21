#include<bits/stdc++.h>
using namespace std;
int n,i,j;int step,steple,thisstep;

int main(){
	cin>>n>>i>>j;
	step=min(min(n-i+1,i),min(n-j+1,j));
	for(int i=1;i<step;i++){
		steple+=4*(n-2*(i-1)-1);
	}
	
	
	//cout<<step;
	if(i==step)cout<<j-step+1+steple;
	else if(j==n-step+1)cout<<i-step+1+n-2*(step-1)-1+steple;
	else if(i==n-step+1)cout<<n-step+1-j+1+2*(n-2*(step-1)-1)+steple;
	else if(j==step)cout<<n-step+1-i+1+3*(n-2*(step-1)-1)+steple;
//	else if (i==step&&j!=step)cout<<thisstep+(j-step);
//	else if (i!=step&&j==step)cout<<steple[step]-(i-step+1);
//	else if (i==n-step+1)cout<<steple[step]-(n-2*(i-1)-1)-(j-step)+1;
//	else if (i!=n-step+1&&j==n-step+1)cout<<thisstep+(n-2*(i-1)-1)+i-step;
//else cout<<111111;
	return 0;
}
