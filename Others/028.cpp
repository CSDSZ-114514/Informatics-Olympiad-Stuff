#include<bits/stdc++.h>
using namespace std;
int main(){
	int n=0,sum=0,mins=1e9;string s[505];bool bre=false;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int len = s[1].length();
	for(int i=1;i<=n;i++){
		sum=0;
		for(int j=1;j<=n;j++){
			bre=false;
			for(int k=0;k<len;k++){
				if(s[j].substr(k)==s[i].substr(0,len-k)){
					if(s[j].substr(0,k)==s[i].substr(len-k)){
						//cout<<s[i].substr(k,s[i].length()-k)<<" "<<k<<endl;
						sum+=k;
						bre = true;
						break;
					}
				}
			}
			if(!bre){
				
				break;
			}
		}
		//cout<<"sum:"<<sum<<endl;
		if(bre){
			mins=min(sum,mins);
		}
	}
	if(mins==1e9){
		cout<<-1;
	}else{
		cout<<mins;
	}
	
}


