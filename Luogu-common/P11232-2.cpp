#include<bits/stdc++.h>
using namespace std;
long long T;long long n,m,l,v0;
long long d[10005],v[10005],a[10005],p[10005],del[10005];
struct QJ{
	long long s,t;
};
QJ qj[10005];
bool cmp(QJ x,QJ y){
	if(x.s>y.s){
		return true;
	}else if(x.s<y.s){
		return false;
	}else{
		if(x.t<y.t){
			return true;
		}else{
			return false;
		}
	}
}
int main(){
	cin>>T;
	while(T--){
		cin>>n>>m>>l>>v0;
		for(int i=1;i<=n;i++){
			cin>>d[i]>>v[i]>>a[i];
		}
		for(int i=1;i<=m;i++){
			cin>>p[i];
		}
		sort(p+1,p+m+1);
		long long cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				if(v[i]>v0){
					qj[++cnt].s=lower_bound(p,p+m+1,d[i])-p;
					qj[cnt].t=m;
					if(qj[cnt].s>qj[cnt].t){
						cnt--;
					}
				}else{
					continue;
				}
			}else if(a[i]>0){
				if(v[i]>v0){
					qj[++cnt].s=lower_bound(p,p+m+1,d[i])-p;
					qj[cnt].t=m;
					if(qj[cnt].s>qj[cnt].t){
						cnt--;
					}
				}else{
					double pos=(v0*v0-v[i]*v[i])/(2.0*a[i]);
					qj[++cnt].s=upper_bound(p,p+m+1,d[i]+pos)-p;
					qj[cnt].t=m;
					if(qj[cnt].s>qj[cnt].t){
						cnt--;
					}
				}
			}else{
				if(v[i]<=0){
					continue;
				}else{
					double pos=(v0*v0-v[i]*v[i])/(2.0*a[i]);
					qj[++cnt].s=lower_bound(p,p+m+1,d[i])-p;
					qj[cnt].t=lower_bound(p,p+m+1,d[i]+pos)-p-1;
					if(qj[cnt].s>qj[cnt].t){
						cnt--;
					}
				}
			}
		}
//		for(int i=1;i<=cnt;i++){
//			cout<<qj[i].s<<" ";
//			cout<<qj[i].t<<endl;
//		}
		sort(qj+1,qj+cnt+1,cmp);
		long long lastt=1e9;
		for(int i=cnt;i>=1;i--){
			if(qj[i].t>lastt){
				del[i]=1;
			}else{
				
			}
		}
	}
	return 0;
}
