#include<bits/stdc++.h>
using namespace std;

typedef int INT;
#define int long long

const int N = 1e5+10;
const int M = 1e18+10;
const int MAX = LONG_LONG_MAX;

int n, money;
int a[N][2];	//a[i][0]为偶数位的，a[i][1]为奇数位的 
int idx[N];
int bestidx, besttotal;

int read(){
	int num = 0;
	char c = getchar();
	while(!isdigit(c)){
		c = getchar();
	}
	while(isdigit(c)){
		num = (num << 1) + (num << 3) + c - '0';
		c = getchar();
	}
	return num;
}

bool cmp(int i1, int i2){
	if(i1 == bestidx){
		return false;
	}else if(i2 == bestidx){
		return true;
	}else{
 		return a[i1][1] < a[i2][1];
 	} 
}

int Solve(){
	sort(idx+1,idx+n+1,cmp);
	int sum = 0;
	int p = 1;
	while(a[idx[p]][1] < besttotal/2 && idx[p] != bestidx){
		sum += a[idx[p]][1];
		//printf("%lld\n",a[idx[p]][1]);
		p ++;
	}
	p --;
	//printf("!%lld, %lld\n", a[bestidx][1], besttotal);
	if(sum <= money){
		int ans = 0; 
		sum = 0;
		for(int i = 0; i <= n; i ++){
			if(i > 0 && (a[idx[i]][1] >= besttotal/2 || idx[i] == bestidx)) break;
			if(i > 0) sum += a[idx[i]][1];
			int money2 = money - sum;
			if(money2 < 0) break;
			int div = money2 / besttotal;
			if(money2 - div*besttotal >= a[bestidx][1]){
				ans = max(ans, i + div*2 + 1);
				//printf("%lld\n", i + div*2 + 1);
			}else{
				ans = max(ans, i + div*2);
				//printf("%lld\n", i + div*2);
			}
		}
		return ans;
		/*
		//重复三遍来减小误差（确信） 
		int money2 = money - sum;
		int p2 = p;
		int div = money2 / besttotal;
		p2 += div*2;
		if(money2 - div*besttotal >= a[bestidx][1]){
			p2 ++;
		}
		int p3 = p - 1;
		if(p3 < 1) return p2;
		int money3 = money2 + a[idx[p]][1];
		div = money3 / besttotal;
		p3 += div*2;
		if(money3 - div*besttotal >= a[bestidx][1]){
			p3 ++;
		}
		int p4 = p - 2;
		if(p4 < 1) return max(p2, p3);
		int money4 = money3 + a[idx[p-1]][1];
		div = money4 / besttotal;
		p4 += div*2;
		if(money4 - div*besttotal >= a[bestidx][1]){
			p ++;
		}
		return max(p2, max(p3, p4));
		//printf("%lld, %lld, %lld,%lld,%lld\n",money,div,money - div*besttotal,a[bestidx][1],a[bestidx][0]);
		//printf("A");
		*/
	}else{
		p = 1;
		sum = 0;
		while(sum <= money && p <= n){
			sum += a[idx[p]][1];
			p ++;
		}
		p --;
		//printf("B");
		return p;
	}
}

INT main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	
	bestidx = 0;
	besttotal = MAX;
	n = read(); money = read(); 
	for(int i = 1; i <= n; i ++){
		idx[i] = i;
		int t1 = read(), t2 = read();
		a[i][1] = t1; a[i][0] = t2;
		if(t1 + t2 < besttotal || t1 + t2 == besttotal && t2 < a[bestidx][0]){
			//printf("%lld -> %lld\n",besttotal,t1+t2);
			bestidx = i;
			besttotal = t1 + t2;
		}
	}
	printf("%lld\n", Solve());
	return 0;
}
