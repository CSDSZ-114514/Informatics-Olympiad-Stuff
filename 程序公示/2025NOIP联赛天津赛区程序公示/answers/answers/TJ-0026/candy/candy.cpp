#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;

//struct NODE{
//    int fr;
//    int tot;
//};

long long n;
long long m;
long long fr[N];
//NODE cn[N];

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);

	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);

	cin>>n>>m;
//	cout<<n<<" "<<m<<"\n";
//	int x;
//	int y;
	long long se;
	long long totMin=2e9+5;
	long long frfr;
//	cout<<totMin;
	for(int i=1;i<=n;i++){
//        cin>>x>>y;
//        cn[i].fr=x;
//        cn[i].tot=x+y;
		cin>>fr[i]>>se;
		if(fr[i]+se<totMin){
			totMin=fr[i]+se;
			frfr=fr[i];
		}else if(fr[i]+se==totMin&&fr[i]<frfr){
			totMin=fr[i]+se;
			frfr=fr[i];
		}
//		totMin=min(totMin,fr[i]+se);
	}
	
//	cout<<frfr<<" "<<totMin<<"\n";
	
	sort(fr+1,fr+n+1);
	
//	for(int i=1;i<=n;i++){
//		cout<<fr[i]<<"\n";
//	}
	
	int ans=m/totMin;
	ans<<=1;
	int mm=m%totMin;
	
	for(se=1;se<=n;se++){
		if(fr[se]<=mm){
			mm-=fr[se];
			ans++;
		}else{
			break;
		}
	}
	
	int ans1=ans;
	int ans2=ans;
	
	do{
		ans=max(ans,ans1);
		ans=max(ans,ans2);
		ans1=ans2;
		
		ans1--;
		mm+=(totMin-frfr);
		for(se;se<=n;se++){
			if(fr[se]<=mm){
				mm-=fr[se];
				ans1++;
			}else{
				break;
			}
		}
		
		ans2=ans1;
		ans2--;
		mm+=frfr;
		for(se;se<=n;se++){
			if(fr[se]<=mm){
				mm-=fr[se];
				ans2++;
			}else{
				break;
			}
		}
		
	}
	while(ans1>=ans||ans2>=ans);
	
	ans=max(ans,ans1);
	ans=max(ans,ans2);
	
	cout<<ans;
	
//	cout<<ans<<" "<<ans1<<" "<<ans2<<"\n";
	
//	cout<<ans1;
	
//	mm=m;
//	int ans2=0;
//	
//	for(int i=1;i<=n;i++){
//		se=fr[i]<<1;
//		if(se<=totMin&&fr[i]<=mm){
//			mm-=fr[i];
//			ans2++;
//		}else{
//			break;
//		}
//	}
//	
//	if((frfr<<1)<=totMin&&mm>=(totMin-frfr)){
//		mm-=totMin-frfr;
//		ans2++;
//	}
//	
//	ans2+=mm/totMin;
//	
//	cout<<ans2;
	
//	for(int i=1;i<=n;i++){
//		se=fr[i]<<1;
//		if(se>totMin){
//			break;
//		}
//		if(se==totle&&fr[i]>=)
//	}
//	
//	for(int i=1;i<=n;i++){
//		cout<<fr[i]<<" ";
//	}
	
//	sort(cn+1,cn+n+1,cmp);

	fclose(stdin);
	fclose(stdout);


	return 0;
}
