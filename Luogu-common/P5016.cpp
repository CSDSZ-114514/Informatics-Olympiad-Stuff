#include<bits/stdc++.h>
using namespace std;
long long n,m,c[100005],p1,s1,s2;
long long sum1,sum2,mincha=1e9,minchanum=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	cin>>m>>p1>>s1>>s2;
	c[p1]+=s1;
	for(int i=1;i<m;i++){
		sum1+=c[i]*(m-i);
	}
	for(int i=m+1;i<=n;i++){
		sum2+=c[i]*(i-m);
	}
	for(int i=1;i<=n;i++){
		if(i<m){
			if(mincha>abs(sum1+s2*(m-i)-sum2)){
				mincha=abs(sum1+s2*(m-i)-sum2);
				minchanum=i;
			}
		}else{
			if(mincha>abs(sum1-sum2-s2*(i-m))){
				mincha=abs(sum1-sum2-s2*(i-m));
				minchanum=i;
				//cout<<abs(sum1-sum2-s2*(i-m))<<endl;
			}
		}
		
		
	}
	cout<<minchanum;
}
