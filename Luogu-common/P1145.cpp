#include<bits/stdc++.h>
using namespace std;
queue <int> q,em;
long long k,m;
void initq(){
	q=em;
	for(int i=1;i<=k;i++){
		q.push(i);	
	}
	for(int i=1;i<=k;i++){
		q.push(i+k);	
	}
}
int main(){
	cin>>k;
	//initq();
	m=k;
	while(true){
		//cout<<1;
		//cout<<m;
		//cout<<endl;
		
//		m++; initq();
//		int p=0,lx=k*2;
//		while(true){
//			p++;
//			//cout<<2;
//			int num=q.front();
//			q.pop();
//			
//			if(p==m){
//				//cout<<num<<" ";
//				if(num<=k){
//					if(lx==k){
//						cout<<m;
//						return 0;
//					}
//					break;
//				}else{
//					lx--;
//					p=0;
//				}	
//			}else{
//				q.push(num);
//			}
//		}
		m++;
		bool isok=true;
		int wz=0;
		//cout<<1;
		for(int i=0;i<k;i++){
			wz=(wz+m-1)%(2*k-i);
			//cout<<wz;
			if(wz<k){
				isok=false;
				break;
			}
			if(i==k-1){
				break;
			}
		}
		if(isok){
			cout<<m;
			return 0;
		}
	}
//	initq();
//	for(int i=1;i<=2*k;i++){
//		int s=q.front();
//		cout<<q.front();
//		q.pop();
//		q.push(s);
//	}
	return 0;
}
