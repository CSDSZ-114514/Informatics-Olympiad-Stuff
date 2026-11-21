#include<bits/stdc++.h>
using namespace std;
long long n;
long long c[205][105][105];
void init() {
	for(int i=0; i<=2*n; i++) {
		c[i][0][1] = 1;
	} 
	for(int i=1; i<=2*n; i++) {
		for(int j=1; j<=i; j++) {
			for(int k=1;k<=100;k++){
                c[i][j][k] += (c[i-1][j][k] + c[i-1][j-1][k]);
                c[i][j][k+1]+=(c[i][j][k]/10);
                c[i][j][k]%=10;
            }
		}
	} 
}
long long h[105];
int main(){
    cin>>n;
    init();
    for(int i=1;i<=100;i++){
        h[i] += (c[2*n][n][i] - c[2*n][n-1][i]);
        if(h[i]<0){
            h[i]+=10;
            h[i+1]-=1;
        }
    }   
    bool isz=true;
    for(int i=100;i>=1;i--){
        //cout<<"i:"<<h[i]<<endl;
        if(h[i]!=0)isz=false;
        if(!isz)cout<<h[i];
    }
    if(isz)cout<<0;
    return 0;
}