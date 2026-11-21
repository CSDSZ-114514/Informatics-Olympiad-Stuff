#include<bits/stdc++.h>
using namespace std;
long long n,r,q;
struct pae{
	long long s,w,nu;
}plae[200005],win[100005],los[100005];
bool cmp(pae p,pae q){
	if(p.s!=q.s) {
		return p.s>q.s;
	} else {
		return p.nu<q.nu;
	}
}
void sor(){
	long long i=1,j=1, ij=1;
	while(i<=n/2&&j<=n/2){
		if(win[i].s>los[j].s||((win[i].s==los[j].s)&&(win[i].nu<los[j].nu))){
			plae[ij++]=win[i++];
		}else{
			plae[ij++]=los[j++];
		}
	}

		while(i<=n/2){
			plae[ij++]=win[i++];
		}


		while(j<=n/2){
			plae[ij++]=los[j++];
		}

}
int main(){
	cin>>n>>r>>q;
	n=2*n;
	for(int i=1;i<=n;i++){
		cin>>plae[i].s;
		plae[i].nu=i;
	}

	for(int i=1;i<=n;i++){
		cin>>plae[i].w;
	}
	sort(plae+1,plae+1+n,cmp);

	for(int i=1;i<=r;i++){
		int t=0;
		for(int j=1;j<=n;j+=2){
			++t;
			if(plae[j].w<plae[j+1].w){
				win[t]=plae[j+1];
				win[t].s++;
				los[t]=plae[j];
			}else{
				win[t]=plae[j];
				win[t].s++;
				los[t]=plae[j+1];
			}
		}
		sor();
	}
//	for(int i=0;i<=n;i++){
//		cout<<plae[i].nu<<" "<<plae[i].s<<"  ";
//	}
	cout<<plae[q].nu;
	return 0;
}
