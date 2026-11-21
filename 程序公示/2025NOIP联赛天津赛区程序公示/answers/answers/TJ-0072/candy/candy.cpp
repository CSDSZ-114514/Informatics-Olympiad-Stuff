#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
long long in(){
	char c=getchar();
	long long f=1;long long ff=0;
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		ff=ff*10+c-'0';
		c=getchar();
	}
	return f*ff;
}
long long n,m;
struct node{
	long long x,y,sum;
}f[100010];
long long ans=0;
long long llmin(long long a,long long b){
	return a>b?b:a;
}
long long llmax(long long a,long long b){
	return a>b?a:b;
}
long long br=0;
long long brx=0;
bool cmp(node a,node b){
	return a.x<b.x;
}
bool check=0;
bool check1=0;
bool check2=0;
int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	n=in();m=in();
	long long mn=2e10;
	for(int i=1;i<=n;i++){
		f[i].x=in();
		f[i].y=in();
		f[i].sum=f[i].x+f[i].y;
		if(mn<f[i].sum){
			
		}else if(mn==f[i].sum){
			if(br<f[i].y){
				br=f[i].y;
				brx=f[i].x;
			}
			br=llmax(f[i].y,br);
		}else{
			mn=f[i].sum;
			br=f[i].y;
			brx=f[i].x;
		}
	}
	ans+=m/mn;
	ans*=2;
	m%=mn;
	sort(f+1,f+n+1,cmp);
	int id=0;
	long long ans1=-1;
	ans1=llmax(ans1,ans);
	while(m+br+brx>=f[++id].x&&id<=n){
		if(f[id].x==brx&&f[id].y==br){
			if(check1==1){
					continue;
			}else{
				if(m>=f[id].x){
					m-=f[id].x;
					ans++;
					ans1=llmax(ans,ans1);
					check1=1;
					continue;
				}else if(m+br+brx>=f[id].x){
					ans1=llmax(ans,ans1);
					m+=br;
					ans--;
					continue;
				}else{
					ans1=llmax(ans,ans1);
					continue;
				}
			}
		}
		if(m>=f[id].x){
			m-=f[id].x;
			ans++;
			ans1=llmax(ans,ans1);
			continue;
		}else{
			if(m+br>=f[id].x&&check1==0){
				ans1=llmax(ans,ans1);
				m+=br;
				m-=f[id].x;
				check1=1;
				continue;
			}
			if(m+br+brx>=f[id].x&&check1==0){
				ans1=llmax(ans,ans1);
				m+=(br+brx);
				m-=f[id].x;
				ans--;
				continue;
			}
			if(m+brx>=f[id].x&&check1==1){
				ans1=llmax(ans,ans1);
				m+=brx;
				m-=f[id].x;
				continue;
			}
		}
	}
	cout<<ans1; 
	return 0;
}
