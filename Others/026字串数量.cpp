#include<bits/stdc++.h>
using namespace std;
long long a[10000005],b[100000005],onum;
long long sum;
string s1;


int main(){
	cin>>s1;
	for(int i=0;i<s1.size();i++){
		if(s1[i]=='I'){
			a[i+1]=1;
		}
		if(s1[i]=='O'){
			onum++;
			b[onum]=i+1;
		}
	}
	int temp=0;
	for(int i=1;i<=s1.size();i++){
		if(a[i]!=2){
			a[i]+=temp;
			temp=a[i];
		}
	}
	for(int i=1;i<=onum;i++){
		//cout<<"wei:" << b[i]<<" zuo:"<<a[b[i]-1]<<" you:"<<a[s1.size()]-a[b[i]]<<endl;
		sum+=(a[b[i]-1]*(a[s1.size()]-a[b[i]]));
	}

	cout<<sum;
}
