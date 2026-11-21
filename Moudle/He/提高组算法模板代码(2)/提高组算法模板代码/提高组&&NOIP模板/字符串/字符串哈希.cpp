//字符串哈希：把不同的字符串映射成不同的整数，主要用于解决字符串匹配问题
//哈希函数：将字符串映射成p进制的数字，p通常取质数131或13331，哈希值定义成unsigned long long
//unordered_map 用字符串哈希实现

unordered_map<string, int> m; // 可以使用STL类实现字符串的保存和查找 
 
ULL h[85], p[85], base=131;

//初始化数组p[], 表示base的幂次 
void initP() {
	p[0] = 1;
	for(int i=1; i<=80; i++) {
		p[i] = p[i-1]*base;
	}
} 

//初始化字符串s的哈希函数，并把前i个子字符串的哈希值保存到数组 
void initH(string s) {
	//直接递推 
//	for(int i=0; i<s.size(); i++) {
//		h = h*base+s[i];
//	}
	
	int len = s.size();
	for(int i=1; i<=len; i++) { //防止索引越界，从1开始遍历 
		h[i] = h[i-1]*base + s[i-1]; //h[i]等于前i-1个字符串左移1位，在加当前字符串 
	}
}

//返回区间[L,R] 形成的字符串子串的哈希值 
ULL getH(int L, int R)  {
	return h[R] - h[L-1]*p[R-L+1]; //类似于前缀和形式，右端点哈希值- 前L-1左移（R-L+1)位 
}
 
