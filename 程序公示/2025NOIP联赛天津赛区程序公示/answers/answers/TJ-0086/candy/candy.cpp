# include<bits/stdc++.h>
using namespace std;
long long n,m,a[100010][5],p,mi=INT_MAX,zh,cnt1,cnt2;
long long mi1=INT_MAX,d;
bool f=false;
int main(){
	
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin>>n>>m;
	long long sum=m;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2];
		a[i][3]+=a[i][1];
		a[i][3]+=a[i][2];
		if(a[i][1]<mi){
			mi=a[i][1];
			p=i;
		}
		if(a[i][1]!=a[1][2]){
			f=true;
		}
	}

	for(int i=1;i<=n;i++){
		if(a[i][3]<mi1){
			mi1=a[i][3];
			d=i;
		}
	}
	sum/=mi1;
	cnt2=sum*2;
	if(f==true){
		sum=m;
		while(1){
			mi=INT_MAX;
			if(sum%a[d][3]==0){
				sum/=a[d][3];
				sum*=2;
				cnt1+=sum;
				break;
			}
			if(sum>=a[p][1]){
				sum-=a[p][1];
				cnt1++;
			}
			else{
				break;
			}
			zh=a[p][2];
			a[p][2]=a[p][1];
			a[p][1]=zh;
			for(int i=1;i<=n;i++){
				if(a[i][1]<mi){
					mi=a[i][1];
					p=i;
				}
				else if(a[i][1]==mi){
					if(a[i][2]<a[p][2]){
						mi=a[i][1];
						p=i;
					}
				}
			}
			cout<<p<<" "<<a[p][1]<<endl;
		}	
	}
	if(f==true){
		mi=max(cnt1,cnt2);
		cout<<mi;
	}
	else{
		cout<<cnt2;
	}
	
	
	return 0;
} 
