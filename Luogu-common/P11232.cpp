#include<bits/stdc++.h>
using namespace std;
long long t,n,m,l,V;
long long d[10005],v[10005],a[10005],p[10005],defp[1000005];
double csql[10005],csqr[10005],ans1;
const long long inf=1e9;
int main(){
	freopen("in.in","r",stdin);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	while(t--){
		memset(csql,0,sizeof(csql));
		memset(csqr,0,sizeof(csqr));
		ans1=0;
		cin>>n>>m>>l>>V;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];//cout<<1;
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];//lstp=max(lstp,p[i]);
			defp[p[i]]++;//cout<<2;
		}
		sort(p+1,p+1+m);
		for(int i=1;i<=l+1;i++){
			defp[i]+=defp[i-1];//cout<<3;
			//cout<<defp[i]<<" ";
		}
		//cout<<endl;
		for(int i=1;i<=n;i++){
			//cout<<4;
			if(v[i]>V){
				csql[i]=d[i];
				if(a[i]>=0){
					csqr[i]=l+1;
				}else{
					csqr[i]=min(l+1,d[i]+1.0*v[i]*(V-v[i])/a[i]+0.5*(V-v[i])*(V-v[i])/a[i]);
				}
			}else{
				csqr[i]=l+1;
				if(a[i]<=0){
					csql[i]=l+1;
				}else{
					csql[i]=min(l+1,d[i]+1.0*v[i]*(V-v[i])/a[i]+0.5*(V-v[i])*(V-v[i])/a[i]);
				}
			}
			//
			//cout<<csql[i]<<" "<<csqr[i]<<" "<<(long long)floor(csqr[i])<<" "<<(long long)ceil(csql[i])<<'\n';
			//cout<<(long long)csqr[i]<<" "<<defp[(long long)floor(csqr[i])];
			//cout<<defp[(long long)csqr[i]]<<" "<<defp[(long long)ceil(csql[i])]<<'\n';
			if(defp[(long long)csqr[i]]>defp[(long long)ceil(csql[i])]){
				ans1++;
			}
		}
		cout<<ans1<<" ";
		
		
	}
	return 0;
}
