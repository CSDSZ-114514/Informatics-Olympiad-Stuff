#include<bits/stdc++.h>
using namespace std;
bool flagA=true;
long long n,m,ans,anans,anm;
struct CD{
	long long c1=0,c2=0;
	bool flg=false;
}cd[100005];
bool cmpA(CD x,CD y){
	return x.c1<y.c1;
}
bool cmp(CD x,CD y){
	return (x.c1+x.c2)<(y.c1+y.c2);
}
int main(){ 
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		long long x,y;cin>>x>>y;
		if(x!=y)flagA=false;
		cd[i].c1=x;cd[i].c2=y;
	}
	if(flagA){
		sort(cd+1,cd+n,cmpA);
		cout<<m/(cd[1].c1);
		return 0;
	}
	sort(cd+1,cd+n+1,cmp);
	double mpc=(cd[1].c1*1.0+cd[1].c2*1.0)/2.0;//cout<<mpc;//单价最小那组的单价。
	cd[1].flg=true;
	
	long long locth=0,loc=0;//locth是单价排在最小组单价后的第一个，loc是最小组的地址 
	sort(cd+1,cd+n+1,cmpA);
	for(int i=1;i<=n;i++){
		if(cd[i].flg)loc=i;
	}
	
	for(int i=1;i<=n;i++){
		if(cd[i].c1*1.0>=mpc){
			locth=i;
			break;
		}
		if(cd[i].flg)continue;
		if(m>=cd[i].c1){
			m=m-cd[i].c1;
			ans++;
		}
		//cout<<ans;
	} 
	//cout<<ans<<" ";
	anm=m;anans=ans;
	long long cnt=0;
	while(true){
		//cout<<ans<<endl;
		if(m<(cd[loc].c1+cd[loc].c2)){
			long long nxt=0,nxtt=0;
			if(cnt%2==0)nxt=cd[loc].c1,nxtt=cd[loc].c2;
			else nxt=cd[loc].c2,nxtt=cd[loc].c1;
			//cout<<nxt<<" "<<nxtt;
			if(nxt<=nxtt){
				if(m>=nxt){
					m=m-nxt;
					ans++;
					if(m>=cd[locth].c1){
						m=m-locth;
						ans++;
					}
				}
			}else{
				if(m>=nxt){
					m=m-nxt;
					ans++;
				}
			}
			break;
		}
		if(cnt%2==0){
			m=m-cd[loc].c1;
			ans++;cnt++;
		}else{
			m=m-cd[loc].c2;
			ans++;cnt++;
		}
	}
	
	
	
	
	
	//PT2:从前面扒下来一个贴后面去 
	cnt=0;
	anans--;anm=anm+cd[locth-1].c1;
	while(true){
		//cout<<ans<<endl;
		if(anm<(cd[loc].c1+cd[loc].c2)){
			long long nxt=0,nxtt=0;
			if(cnt%2==0)nxt=cd[loc].c1,nxtt=cd[loc].c2;
			else nxt=cd[loc].c2,nxtt=cd[loc].c1;
			//cout<<nxt<<" "<<nxtt;
			if(nxt<=nxtt){
				if(anm>=nxt){
					anm=anm-nxt;
					anans++;
					if(anm>=cd[locth].c1){
						anm=anm-locth;
						anans++;
					}
				}
			}else{
				if(anm>=nxt){
					anm=anm-nxt;
					anans++;
				}
			}
			break;
		}
		if(cnt%2==0){
			anm=anm-cd[loc].c1;
			anans++;cnt++;
		}else{
			anm=anm-cd[loc].c2;
			anans++;cnt++;
		}
	}
	//cout<<ans<<" "<<anans<<endl;
	cout<<max(anans,ans);
	//人事已尽，天命难违。 
	//NOIP2025 RP++!
	return 0;
}






























































