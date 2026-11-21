//中国剩余定理： 用于求解线性同余方程组，要求模数两两互质
//求解步骤：
//1.计算所有模数的积 M
//2.计算第i个方程的 ci=M/mi
//3.计算ci再模mi下的乘法逆元x: ci*x + mi*y = 1 
//4. 解 x = sum(ri*ci*x)%M


LL CRT(LL m[], LL r[]) {
	LL ans = 0, M=1; 
	for(int i=1; i<=n; i++) {
		M = M * m[i]; //计算所有模数的积M 
	}
	
	//枚举每一个同余方程组 
	for(int i=1; i<=n; i++) {
		LL c = M/m[i]; //更新 ci=M/mi 
		LL x, y;
		exgcd(c, m[i], x, y); //求ci再模mi下的乘法逆元 
		ans = (ans + (__int128)r[i]*c*x%M)%M; //累积结果，注意防止溢出使用__int128 
	} 
	
	return (ans%M + M)%M; //防止出现负数，求最小的正整数 
} 

//扩展中国剩余定理： 求解线性同余方程组，当模数不一定两两互质时
//核心思想：将两个同余方程组合并成一个，经过n-1次合并成一个线性方程
// x = m1*p+r1 = m2*q + r2 -> m1*p + m2*q = r2-r1
// 当 __gcd(m1,m2)|(r2-r1)时有解
//通过扩欧算法求出同余方程的解 p, 通解 P= p+m2/d *k, 将通解P带入第一个同余方程 
// x = m1*(p+m2/d*k)+r1 -> x = m1*m2/d *k + m1*p + r1
// 等价于同余方程： x%(m1*m2/d) =  m1*p + r1, m = m1*m2/d, r = m1*p+r1

//扩展中国剩余定理 
long long EXCRT(LL m[], LL r[]) {
	LL m1, m2, r1, r2;
	m1 = m[1], r1=r[1];
	
	for(int i=2; i<=n; i++) {
		m2 = m[i], r2 = r[i];
		LL p, q, d;
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

