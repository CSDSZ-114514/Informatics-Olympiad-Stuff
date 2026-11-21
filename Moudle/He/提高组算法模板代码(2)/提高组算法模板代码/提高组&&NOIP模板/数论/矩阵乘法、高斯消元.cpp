//简单矩阵乘法：矩阵A：n行*m列  矩阵B：m行*p列   C=A*B 
	for(int i=1; i<=n; i++) { //枚举行 
		for(int j=1; j<=p; j++) {//枚举列 
			for(int k=1; k<=m; k++) {
				c[i][j] += a[i][k]*b[k][j]; //同位置相乘在相加 
			}
		}
	}
	
//矩阵快速幂
//结构体表示矩阵 
struct matrix {
	ll c[105][105];
	
	matrix() {
		memset(c, 0, sizeof(c)); //注意清空数组值 
	}
	
	//重载乘法运算符 
	matrix operator*(matrix x) {
		matrix t;
		
		for(int i=1; i<=n; i++) {//枚举行 
			for(int j=1; j<=n; j++) {//枚举列 
				for(int k=1; k<=n; k++) {
					t.c[i][j] = (t.c[i][j] + c[i][k]*x.c[k][j])%mod;
				}
			}
		}
		return t;
	}
};

matrix qpow(matrix a, ll b) {
	matrix res; //创建单位矩阵 
	for(int i=1; i<=n; i++) {
		res.c[i][i] = 1;
	}
	while(b) {
		if(b%2==1) {
			res = res * a;  //使用矩阵运算符重载 
		}
		b/=2; //幂次除二 
		a = a*a; //底数平方 
	}
	return res;
}  

//………………………………………………………………………… 
//高斯消元法用于求解线性方程组的解
//当n行主元都能枚举成功，方程组唯一解
//如果存在主元为0，
//1）如果存在对应常数项不为0，则方程无解
//2）否则对应常数项为0，则方程无穷解
//如果需要取分无解和无穷解，找主元行时，需要从第一行开始寻找
//当前行前面的行如果不是主元行，即主元位置为0，也可以作为当前主元行

bool gauss() {
	for(int i=1; i<=n; i++) { //枚举主元行 
		for(int j=i; j<=n; j++) { //寻找主元位置非0的行 
			if(fabs(a[j][i]) > eps) { //double类型不能直接和0比 
				swap(a[i], a[j]); //两行交换，i行为主元行 
				break;
			}
		}
		
		if(fabs(a[i][i]) <= eps) { //如果主元位置值为0，则无解或无穷解 
			return 0;
		}
		
		//将除主元行之外的其他行，主元位置更新为0 
		for(int j=1; j<=n; j++) {
			if(i==j) continue; //跳过主元行 
			
			double t = a[j][i]/a[i][i]; //将主元行扩大t倍 
			for(int k=i; k<=n+1; k++) {
				a[j][k] -= a[i][k]*t; //更新当前行 
			}
		}
	}
	
	//更新主元为1，a[i][n+1] 为方程的解 
	for(int i=1; i<=n; i++) {
		a[i][n+1] /= a[i][i];
	}
	
	return 1;
} 

