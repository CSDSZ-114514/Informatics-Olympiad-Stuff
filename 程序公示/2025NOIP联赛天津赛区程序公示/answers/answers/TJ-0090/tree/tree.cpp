#include<bits/stdc++.h>

using namespace std;
int t,n,m,pd=0;
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&m);
		for (int i=2;i<=n;i++){
			int p;
			scanf("%d",&p);
			pd=max(pd,p);
		}
		long long sum=0;
		for (int i=1;i<=pd;i++){
			sum+=i;
		}
		cout<<sum<<endl;
		sum=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
