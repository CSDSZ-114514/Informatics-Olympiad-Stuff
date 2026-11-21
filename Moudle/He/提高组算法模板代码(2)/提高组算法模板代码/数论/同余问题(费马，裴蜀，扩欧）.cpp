//费马小定理：若p为质数，且 a,p 互质，则 a^(p-1) ≡ 1 (mod p)
//则 a模p下的乘法逆元是：a^(p-2)%p
//快速幂 
ll qpow(ll a, ll b, ll m) {
	ll ans = 1;
	while(b) {
		if(b%2==1) { //当指数为奇数，先取出一个底数在除二 
			ans = ans * a%m;
		}
		b/=2; //指数除二 
		a = a*a%m; //底数平方 
	}
	return ans;
} 

int main() {
	//费马小定理求a模p下的乘法逆元 
	cout<< qpow(a,p-2, p);
}

—————————————————————————————————————— 
//裴蜀定理：对于多元一次方程，当方程右边的值是左边系数的最大公约数或公约数的倍数
//则方程有解
int main() {
	s = 0; //多元一次方程系数的倍数 
    for(int i=1; i<=n; i++) {
		cin>>a;
		s = __gcd(s, abs(a));
	} 
}

———————————————————————————————————————
//扩展欧几里得算法：根据裴蜀定理和欧几里得算法，求不定方程和同余方程的解
// gcd(a, b) = gcd(b, a%b)  可得方程解之间的关系 x = y1, y= x1-a/b*y1 
//求方程 ax + by = gcd(a, b)的特解x0
// 特解 x0, 则>0 的最小解是：  (x0 %(b/d) + (b/d)) %(b/d)  (d是gcd(a,b)) 
//x，y 保存方程ax + by = gcd(a, b)的特解， 返回值是gcd(a, b) 
ll exgcd(ll a, ll b, ll &x, ll &y) {
	if(b==0) { //递归结束 
		x=1, y=0;
		return a;
	}
	ll x1, y1;
	ll d = exgcd(b, a%b, x1, y1); //获取 bx +(a%b)y = gcd(b,a%b) 方程的解 
	x = y1;  //根据对应关系，更新ax + by = gcd(a, b)方程的解 
	y = x1- a/b*y1;
	return d;
}

//求方程 ax + by = c的解：先求方程 ax + by = gcd(a, b) 的解
//如果c 是d=gcd(a,b) 的倍数，即 c%d == 0, 则方程有解，特解是 x*c/d

//求同余方程 ax ≡ b (mod m)得整数解,先将同余方程转化为不定方程然后求解  
//根据同余问题：ax-b = my -> ax+my=b 求解 (不关心y的解，所以保证y的系数为正数） 

//扩欧算法求乘法逆元，只需要 a, m 互质，求方程 ax ≡ 1 (mod m)的解
//转化为不定方程  ax = my +1 -> ax+my = 1 求解 









