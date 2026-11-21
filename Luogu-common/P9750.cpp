#include<bits/stdc++.h>
using namespace std;
long long T,M;
double a,b,c,x1,q,p;
double bb;
double Delta(){
	return b*b-4*a*c;
}
void yue(double &e,double &f){
	long long g=abs(__gcd(int(e),int(f)));
	e/=g;f/=g;
}
void yue(double &e,long long &f){
	long long g=abs(__gcd(int(e),int(f)));
	e/=g;f/=g;
}
long long k,t;
void sol(long long n){
	for(long long i=sqrt(n);i>=1;i--){
		long long e=n/i/i; 
		if(e*i*i==n){
			k=i;
			t=e;
			return ;
		}
	}
}
 int main(){
	freopen("test.out", "w", stdout);
	cin>>T>>M;	
	for(long long i=1;i<=T;i++){
		cin>>a>>b>>c;
		if(a<0){
			a=-a	;b=-b;c=-c;
		}
		if(Delta()<0){
			cout<<"NO"<<endl;
		}else if(Delta()==0){
			if(b!=0){
				double g=2*a;
				yue(g,b);
				if(g==1){
					cout<<-b<<endl;
				}else{
					cout<<-b<<"/"<<g<<endl;
				}
			}else{
				cout<<"0"<<endl;
			}
		}else if(Delta()>0){
			long long sq=sqrt(Delta());
			if(sq*sq==Delta()){
				double fenzi=-b+sq;
				long long g=2*a;
				yue(fenzi,g);
				if(g!=1){
					cout<<fenzi<<"/"<<g<<endl;
				}else{
					cout<<fenzi<<endl;
				}
			}else{
				if(b!=0){
					bb=b;
					double g=2*a;
					yue(g,b);  
					if(g==1){
						cout<<-b<<"+";
					}else{
						cout<<-b<<"/"<<g<<"+";
					}
				}
				if(bb!=0){
					b=bb;
				}
				double g=2*a;
				sol( Delta());
				yue(g,k);
				if(k!=1){
					cout<<k<<"*"<<"sqrt("<<t<<")";
				}else{
					cout<<"sqrt("<<t<<")";
				}
				if(g!=1){
					cout<<"/"<<g<<endl;
				}else{
					cout<<endl;
				}
			}
		}
	}
}
