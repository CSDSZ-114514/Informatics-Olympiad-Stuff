//组合数求解：
//1. 递推法求解 c[n][m] = c[n-1][m] + c[n-1][m-1]  时间复杂度O(n^2)
void init() {
	//初始化 c[i][0]=1; 
	for(int i=0; i<=n; i++) {
		c[i][0] = 1;
	} 
	//杨辉三角可以表示组合数
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			c[i][j] = (c[i-1][j] + c[i-1][j-1])%p;
		}
	} 
}

//2. 快速幂求组合数：当递推法超时，根据组合数公式，采用快速幂求组合数
//要求：p为质数，n<p, 求 c[n][m]%p
//维护两个数组  f[x]:存 x! (mod p) 的值    g[x]:存 (x!)-1 (mod p)的值
//根据费马小定理：g[x] = qpow(f[x], p-2, p)
//则 c[n][m]%p = f[n]*g[n-m]%p*g[m]%p;

//快速幂 
ll qpow(ll a, ll b, ll m) {
	ll ans = 1;
	while(b) {
		if(b%2==1) {
			ans = ans * a%m;
		}
		b/=2;
		a= a*a%m;
	}
	return ans;
}
void init() {
	f[0]= g[0] = 1;
	//递推求 f[i] 
	for(int i=1; i<=n; i++) {
		f[i] = f[i-1]*i%p;
	} 
	
	g[n] = qpow(f[n], p-2, p); //费马小定理 
	for(int i=n-1; i>=1; i--) { //逆向递推求g[x] 
		g[i] = g[i+1]*(i+1)%p;
	}
}
int  getC(int  n, int  m, int p) {
	if(n<m) return 0;
	
	return f[n]*g[n-m]%p*g[m]%p;
}

//lucas(卢卡斯）定理求组合数：当递推算法超时，但不能保证n<p,
//则不能保证 n!和p互质，因此不能使用费马小定理求乘法逆元
//lucas定理： c[n][m] %p = c[n/p][m/p] * c[n%p][m%p] %p
//因为 n%p<p, 则右面采用快速幂求组合数，左边根据lucas定理继续递归直到 m=0，返回1
 
int  getC(int  n, int  m, int p) {
	if(n<m) return 0;
	
	return f[n]*g[n-m]%p*g[m]%p;
}
int  lucas(int  n, int  m, int  p) {
	if(m==0) return 1;
	return lucas(n/p, m/p,p) * getC(n%p, m%p,p) %p;
}


//利用高精度加法求组合数：c[i][j][k]：第三个维度用来保存组合数上的每一位数
for(int i=0; i<=2*n; i++) {
	c[i][0][0] = 1; //初始化 c[i][0] 
}

for(int i=1; i<=2*n; i++) {
	for(int j=1; j<=i; j++) {			
		for(int k=0; k<=100; k++) { //枚举每一位 
			c[i][j][k] += c[i-1][j][k]+c[i-1][j-1][k]; //同位相加 
			c[i][j][k+1] += c[i][j][k]/10; //进位 
			c[i][j][k]%=10; //存余 
		}
	}
}
 



	
