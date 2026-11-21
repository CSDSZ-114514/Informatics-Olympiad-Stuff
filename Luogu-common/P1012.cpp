#include<bits/stdc++.h>
using namespace std;
long long n,sumlen;
string bx;
struct aaa{
	string cx;
	bool unused=true;
	
}ax[105];
bool compare_int(string s1,string s2){
	//int s1le=s1.length(),s2le=s2.length();
	string s3=s1+s2,s4=s2+s1;
	if(s3>s4){
		return 1;
	}else{
		return 0;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ax[i].cx;
	}
	ax[0].cx="0";
	//cout<<ax[1].cx<<" "<<ax[2].cx<<" "<<ax[3].cx;
	for(int i=1;i<=n;i++){
		int temp=0;
		for(int j=1;j<=n;j++){
			if(compare_int(ax[j].cx,ax[temp].cx)&&ax[j].unused){
				temp=j;
			}//cout<<temp<<" ";
		}
		bx=bx+ax[temp].cx;
		ax[temp].unused=false;
		//cout<<endl;
	}
	cout<<bx;
//	string s1,s2;
//	cin>>s1>>s2;
//	cout<<compare_int(s1,s2);
	return 0;
}

