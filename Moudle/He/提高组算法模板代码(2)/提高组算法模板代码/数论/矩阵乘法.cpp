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
	matrix res; //创建单位举证 
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
