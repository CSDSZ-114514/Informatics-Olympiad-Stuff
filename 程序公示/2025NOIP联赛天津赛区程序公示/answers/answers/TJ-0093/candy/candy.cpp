#include<fstream>
#define inf 10e10
using namespace std;
ifstream cin("candy.in");
ofstream cout("candy.out");
struct node{
	long long x,y;
}pr[10000];
int c(int value,bool Ij,bool IIj,bool c1,int summ){
	if(c1){
		//choose 1
		if(Ij && value>=pr[0].x) value-=pr[0].x;
		else if(!Ij && value>=pr[0].y) value-=pr[0].y;
		else return summ;//if(value<pr[0].x || value<pr[0].y) return summ;
		summ++;
		return max(c(value,!Ij,IIj,true,summ),c(value,!Ij,IIj,false,summ));
	}else{
		//choose 2
		if(IIj && value>=pr[1].x) value-=pr[1].x;
		else if(!IIj && value>=pr[1].y) value-=pr[1].y;
		else return summ;//if(value<pr[1].x || value<pr[1].y) return summ;
		summ++;
		return max(c(value,Ij,!IIj,true,summ),c(value,Ij,!IIj,false,summ));
	}
}
int main(){
	int n,m;
	cin>>n>>m;
	bool flagA=true,flagB=true;
	long long minn=inf;
	for(int i=0;i<n;i++){
		cin>>pr[i].x>>pr[i].y;
		minn=min(minn,pr[i].x);
		if(pr[i].x!=pr[i].y) flagA=false;
		if(pr[i].x<pr[i].y) flagB=false;
	}if(flagA){
		//թƭ
		 cout<<m/minn;
		 return 0;
	}if(n==1){
		//duishu
		int pair=m/(pr[0].x+pr[0].y);
		int summ=2*pair;
		int sheng=m-(pr[0].x+pr[0].y)*pair;
		if(sheng>pr[0].x)cout<<summ+1;
		else cout<<summ;
		return 0;
	}if(n==2){
		cout<<max(c(m,true,true,true,0),c(m,true,true,false,0));
	}
	
	cin.close();cout.close();
	return 0;
}
