#include<bits/stdc++.h>
using namespace std;
long long n,ans,mxx;
void  prime_factorization(int x){
	for(long long i=2;i<=sqrt(x);i++){
		if(x%i==0) {
			long long cnt=0;
			while(x%i==0){
				cnt++;
				x/=i;
			}
			long long j=0;
			while(true){
				j++;
				if(cnt>=j){
					cnt-=j;
					ans++;
				}
				else break;
			}
		}
		
	}
	if(x>1){
		ans++;
	}
}
int main(){
	cin>>n;
	prime_factorization(n);
	cout<<ans;
	return 0;
}
