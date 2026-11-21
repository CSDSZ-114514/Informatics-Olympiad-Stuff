#include<bits/stdc++.h>
using namespace std;
long long n,maxs=-1e9;
struct tree{
	long long val,l=-1,r=-1,sub=-1;
}tr[1000005];
bool check(long long r1,long long r2){
	if(r1==-1&&r2==-1){
		return true;
	}
	if(r1==-1||r2==-1){
		return false;
	}
	if(tr[r1].val!=tr[r2].val){
		return false;
	}
	else{
		if(check(tr[r1].l,tr[r2].r)&&check(tr[r2].l,tr[r1].r)){
			return true;
		}else{
			return false;
		}
	}
}
long long cal(int nu){
	
	if(tr[nu].sub!=-1){
		return tr[nu].sub;
	}
	tr[nu].sub=0;
	if(tr[nu].l!=-1){
		tr[nu].sub+=cal(tr[nu].l);
	}
	if(tr[nu].r!=-1){
		tr[nu].sub+=cal(tr[nu].r);
	}
	tr[nu].sub+=1;
	return tr[nu].sub;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>tr[i].val;
	}
	for(int i=1;i<=n;i++){
		cin>>tr[i].l>>tr[i].r;
	}
	for(int i=1;i<=n;i++){
		if(check(i,i)){
			//cout<<1111;
			maxs=max(cal(i),maxs);
			
		}
	}
	cout<<maxs;
}
