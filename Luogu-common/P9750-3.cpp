#include<bits/stdc++.h>
using namespace std;
long long T,M;long long a,b,c;
void yf(long long &aa,long long &bb){
	long long zdgys=__gcd(aa,bb);
	aa/=zdgys;bb/=zdgys;
	if(bb<0){
		aa=aa*-1;
		bb=bb*-1;
	}
}
void hjgh(long long &ug,long long &lg){
	long long leftroot=1;bool hereiswqpf=true;
	while(hereiswqpf){
		hereiswqpf=false;long long maxwqpf=1;
		for(int i=2;i<=ceil(sqrt(ug));i++){
			//cout<<sqrt(ug)<<" ";
			//cout<<ug;
			if(ug%(i*i)==0){
				hereiswqpf=true;
				maxwqpf=i;
			}
		}
		if(hereiswqpf){
			//cout<<maxwqpf<<" ";
			ug/=(maxwqpf*maxwqpf);
			leftroot*=maxwqpf;
		}
	}
	lg=leftroot;
	return;
}
void qh(long long &fz1,long long &fm1,long long &fz2,long long &fm2){
	long long zxgbs=(fm1*fm2)/__gcd(fm1,fm2);
	long long fs1cs=zxgbs/fm1,fs2cs=zxgbs/fm2;
	fm1=zxgbs;fm2=zxgbs;fz1*=fs1cs;fz2*=fs2cs;
	fz1+=fz2;
	yf(fz1,fm1);
}

int main(){
	freopen("P9750.txt","w",stdout);
	cin>>T>>M;
	for(int i=1;i<=T;i++){
		a=0;b=0;c=0;
		cin>>a>>b>>c;
		long long delta=b*b-4*a*c;
		if(delta<0){
			cout<<"NO"<<endl;
			continue;
		}
		long long fenz1=-1*b,fenmu1=2*a;
		yf(fenz1,fenmu1);
		long long ghn=delta,ghw=1,fenmu2=2*a;
		hjgh(ghn,ghw);
		yf(ghw,fenmu2);
		if(ghn==1){
			qh(fenz1,fenmu1,ghw,fenmu2);
			cout<<fenz1;
			if(fenmu1!=1){
				cout<<fenmu1;
			}
		}else{
			bool atlst1=true;
			if(fenz1!=0){
				atlst1=false;
				if(fenmu1==1){
					cout<<fenz1;
				}else{
					cout<<fenz1<<"/"<<fenmu1;
				}
			}
			if(delta!=0&&fenz1!=0){
				cout<<"+";
			}
			if(delta!=0){
				if(ghw!=1){
					atlst1=false;
					cout<<ghw;	
				}
				if(ghw!=1&&ghn!=1){
					cout<<"*";
				}
				if(ghn!=1){
					atlst1=false;
					cout<<"sqrt("<<ghn<<")";
				}
				if(fenmu2!=1){
					cout<<"/"<<fenmu2;
				}
			}
			if(atlst1){
				cout<<0;
			}
		}
		
		cout<<endl;
	}
//	long long c=1,d=6,a=1,b=3;
//	qh(a,b,c,d);
//	cout<<a<<"/"<<b;
}
