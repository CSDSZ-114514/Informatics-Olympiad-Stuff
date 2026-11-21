#include<bits/stdc++.h>
using namespace std;
struct ab{
	int num,ind;
}a[8005];
long long n,Q,mod,t1,t2;
void qsort(){
	for (int i = 1; i <= n; i++){
		for (int j = i; j >= 2; j--){
			if (a[j].num < a[j-1].num) {
				swap(a[j-1],a[j]);
			}
		}	
	}
}
int main(){
	cin>>n>>Q;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		a[i].ind=i;
	}
	qsort();
		
	for(int i=1;i<=Q;i++){
		cin>>mod;
		if(mod==1){
			cin>>t1>>t2;
			long long ind2;
			for(int j=1;j<=n;j++){
				if(a[j].ind==t1){
					a[j].num=t2;
					ind2=j;
				}
			}
			

				for(int j=ind2;j>1;j--){
					if ((a[j].num < a[j-1].num)||(a[j].num ==a[j-1].num&&a[j].ind < a[j-1].ind)) {
						swap(a[j-1],a[j]);
					}else{
						break;
					}
				}


				for(int j=ind2;j<n;j++){
					if ((a[j].num > a[j+1].num)||(a[j].num ==a[j+1].num&&a[j].ind > a[j+1].ind)) {
						swap(a[j+1],a[j]);
					}else{
						break;
					}
				}

		}else{
			cin>>t1;
			for(int i=1;i<=n;i++){
				if(a[i].ind==t1){
					cout<<i<<endl;
					break;
				}
			}
		}
	}
}
