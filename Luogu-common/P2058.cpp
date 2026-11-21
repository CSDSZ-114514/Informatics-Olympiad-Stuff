#include<bits/stdc++.h>
using namespace std;
struct B{
	long long t,k;
	vector<long long> a;
}b[100005];
long long n,t[100005],x,ind,num;
int main(){
	ind=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>b[i].t>>b[i].k;
		for(int j=1;j<=b[i].k;j++){
			cin>>x;
			b[i].a.push_back(x);
			t[x]++;
			if(t[x]==1){
				num++;
			}
		}
		while(b[i].t-b[ind].t>=86400){
			for(int z:b[ind].a){
				t[z]--;
				if(t[z]==0){
					num--;
				}
			}
			ind++;
		}
		cout<<num<<endl;
	}
		
	
	
}
