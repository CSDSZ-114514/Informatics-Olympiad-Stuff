#include <bits/stdc++.h>
using namespace std;
using namespace std;
int a[100000005];
void  prime_factorization(int x){
	for(int i=2;i<=sqrt(x);i++){
		while(x%i==0){
			a[i]++;
			x/=i;
		}
	}
	if(x>1){
		a[x]++;
	}
}
int main(){
	int N;
	cin>>N;
	//for(int i=N;i>1;i--){
		prime_factorization(N);
	//}
	
	for(int i=2;i<=N;i++){
		if(a[i]!=0){
			cout<<i<<" "<<a[i]<<endl;
		}
	}
	return 0;
} 
