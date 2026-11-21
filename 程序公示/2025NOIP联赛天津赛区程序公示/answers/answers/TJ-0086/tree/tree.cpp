# include<bits/stdc++.h>
using namespace std;
long long n,a[8100],cnt,t,sum,b[8100],ma=INT_MIN,m,sum1;
int main(){
	
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin>>t;
	for(int e=1;e<=t;e++){
		cin>>n>>m;
		for(int i=1;i<n;i++){
			cin>>a[i];
			if(a[i]==1){
				sum++;
			}
			b[a[i]]++;
		}
		if(m==n-1){
			for(int j=1;j<=n;j++){
				sum1+=j;
			}
			cout<<sum1<<endl;
			sum1=0;
		}
		else if(m==2){
			for(int i=2;i<=n;i++){
				if(b[i]!=0){
					sum+=b[i];
					sum+=1;
					ma=max(ma,b[i]); 
				}
			}
			sum+=ma;
			sum+=2; 
			cout<<sum<<endl;
			sum=0;
		}
	}
	return 0;
} 
