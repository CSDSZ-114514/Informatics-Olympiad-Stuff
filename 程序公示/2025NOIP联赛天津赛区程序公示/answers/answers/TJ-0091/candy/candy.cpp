#include<bits/stdc++.h>
using namespace std;
struct candy{
	int x,y;
}c[110000];
int s[110000];
int d[110000],cnt[110000];
bool cmp(candy a,candy b){
	return a.x<b.x;
}
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	int n;
	long long m;
	int tot=0,t=0,cntn=1;
	int sum=0,ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i].x>>c[i].y;
		s[i]=c[i].x+c[i].y;
	}
	sort(c+1,c+n+1,cmp);
	sort(s+1,s+n+1);
	if(m<c[1].x){
		cout<<0<<endl;
		return 0;
	}
	if(m>=c[1].x&&m<min((c[1].x+c[2].x),s[1])){
		cout<<1<<endl;
		return 0;
	}else if(m==min((c[1].x+c[2].x),s[1])){
		cout<<2<<endl;
		return 0;
	}else{
		for(int i=1;i<=n;i++){
			sum+=c[i].x;
			cnt[cntn]++;
			if(sum>s[1]){
				sum=c[i].x;
				cntn++;
			}
			if(c[i].x>s[1]) break;
		}
		int num=0;
		for(int i=1;i<=n;i++){
			if(cnt[i]>2){
				num++;
			}
		} 
		t=m%s[1]+num*s[1];
		ans=2*(m/s[1])-2*num;
		for(int i=1;i<=n;i++){
			if(t<c[i].x){
				break;
			}
			t-=c[i].x;
			tot++;
		}
		for(int i=1;i<=tot;i++){
			d[i]=c[i].y;
		}
		sort(d+1,d+tot+1); 
		for(int i=1;i<=n;i++){
			if(d[i]==0) continue;
			if(t<d[i]){
				break;
			}
			t-=d[i];
			tot++;
		}
		cout<<ans+tot<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
