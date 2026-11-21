#include<bits/stdc++.h>
using namespace std;
long long A,B,L,bea=L,beb=1,ben;

int main(){
	cin>>A>>B>>L;
	bea=L;
	for(long long i=1;i<=L;i++){
		for(long long j=1;j<=L;j++){
			if(i*B>=j*A&&__gcd(i,j)==1){
				if(j*bea>i*beb){
					bea=i;beb=j;
				}
			}
		}
	}
	cout<<bea<<" "<<beb;
}
