#include<bits/stdc++.h>
using namespace std;
long long n;
long long m[1000005], a[1000005];
long long exgcd(long long a, long long b, long long &x, long long &y) {
	if(b==0) {
		x=1, y=0;
		return a;
	}
	long long x1, y1;
	long long d = exgcd(b, a%b, x1, y1);  
	x = y1;  
	y = x1- a/b*y1;
	return d;
}
long long m1 = 0;
long long EXCRT(long long m[], long long r[]) {
	long long  m2, r1, r2;
	m1 = m[1], r1=r[1];
	
	for(int i=2; i<=n; i++) {
		m2 = m[i], r2 = r[i];
		long long p, q, d;
		d = exgcd(m1, m2, p, q); //求同余方程 m1*p+m2*q = r2-r1的解 
        if((r2-r1)%d) { //判断是否有解 
            return -1;
        }
		p = p*(r2-r1)/d;  //更新解 
		p = (p%(m2/d) + m2/d)%(m2/d); //获得最小正整数解 
		
		r1 = m1*p + r1; //更新新的余数 
		m1 = m1 * m2/d; // 更新新的模数	
	}
	return (r1%m1 + m1)%m1;  //获得最小正整数解 
}

int main(){
    cin>>n;
    for (int i = 1; i <= n;i++){
        cin >> m[i] >> a[i];
    }
    long long l,r;
    cin >> l >> r;
    long long rt = EXCRT(m, a);
    if(rt==-1){
        cout << 0;
        return 0;
    }
    long long cnt = 0;
    while(rt<=r){
        if(rt<=r&&rt>=l){
            cnt++;
        }
        rt += m1;
    }
    cout << cnt;
}