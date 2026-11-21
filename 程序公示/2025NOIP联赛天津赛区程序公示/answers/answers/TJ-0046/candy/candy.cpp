#include<bits/stdc++.h>

using namespace std;

struct price{
	long long x,y;
};

long long n,m,minn = 1e12,ans,w[100005],cost,flag=1e10;
price c[100005];

int cmp(price a,price b){
	return a.x  < b.x;
}

int main(){
	freopen("candy.in","r",stdin);
	freopen("candy.out","w",stdout);
	cin >>n >> m;
	for (int i = 1;i <= n;i++){
		cin >> c[i].x >> c[i].y;
		minn = min(minn,c[i].x + c[i].y);
	}
	sort(c+1,c+n+1,cmp);
	for (int i = 1;i <= n;i++){
		if (c[i].x+c[i+1].x <= minn){
			//cout << c[i].x <<" "<<c[i].y<<endl;
			if (minn - c[i].x == c[i].y){
				flag = min(flag,c[i].y);
			}
			if (m >= c[i].x){
				m -= c[i].x;
				ans++;
			}
			else break;
		}
		else{
			//cout << c[i].x <<" "<<c[i].y<<endl;
			ans += 2 * (m / minn);
			m -= (m / minn)*minn;
			if (m >= min(flag,c[i].x)) ans++;
			break;
		}
	} 
	cout << ans<<endl;
	//cout << m << endl;
	return 0;
}
