#include<bits/stdc++.h>
using namespace std;
struct ci{
	long long a,b;
}ct[10000005];
long long n,f[10000005],len;
bool cmp(ci x,ci y){
	return x.a<y.a;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>ct[i].a>>ct[i].b;
	}
	sort(ct+1,ct+1+n,cmp);
	f[1]=ct[1].b;
	len=1;
	for(int i=2;i<=n;i++){
		if(ct[i].b>f[len]){
			f[++len]=ct[i].b;
		}else{
			int index=lower_bound(f+1,f+len+1,ct[i].b)-f;
			f[index]=ct[i].b;
		}
	}
	cout<<len;
}
