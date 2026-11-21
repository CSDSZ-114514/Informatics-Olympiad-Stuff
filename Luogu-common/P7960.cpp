#include<bits/stdc++.h>
using namespace std;
long long fs[10000005],p[10000005],ns[10000005],T,x;
void sf(){
	long long nk=0;
	for(int i=1;i<=1e7+3;i++){
		if(fs[i]==0){
			long long ti=i;bool isseven=false;
			while(ti!=0){
				int b=ti%10;
				if(b==7){
					isseven=true;
					break;
				}ti/=10;
			}
			if(isseven){
				for(int j=1;i*j<=1e7+3;j++){
					fs[i*j]=1;
				}
			}else{
				p[i] = ++nk;
				ns[nk]=i;
			}
		}else{
			continue;
		}
	}
			

}
int main(){
	sf();
	cin>>T;
	for(int i=1;i<=T;i++){
		cin>>x;
		if(fs[x]==1){
			cout<<-1<<endl;
		}else{
			cout<<ns[p[x]+1]<<endl;
			
		}
	}
}
