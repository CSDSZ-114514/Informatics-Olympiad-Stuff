//AC自动机：用来处理字符串匹配问题，是多模式匹配算法，
//通常给定n个模式串和一个主串，查找有多少模式串在主串中出现过
//kmp算法是查找一个模式串是否在主串中出现过

//n个模式串创建字典树 
void insert(string s) {
	int p =0 ; //设置根节点 
	for(int i=0; i<s.size(); i++) { //枚举每一个字符 
		int j = s[i]-'a';
		if(t[p][j]) { //如果子结点存在 
			p = t[p][j]; //指向子结点 
		} else {
			t[p][j] = ++idx; //创建新节点 
			p = t[p][j];
		}
	}
	cnt[p]++; //保存字符串出现的次数 
}

//创建AC自动机：为字典树的每一个节点更新回跳边或转移边
//回跳边：指向父节点的回跳边所指节点的儿子，用数组ne表示 
//        回跳边所指节点是当前节点表示字符串的最长后缀
//转移边： 指向当前节点的回跳边所指节点的儿子
//         转移边所指节点是当前节点的最短路
//通过bfs依次访问字典树的每个节点，创建AC自动机 
void build() {
	queue<int> q;
	 
	//将根节点的所有子结点入队， ne[u]=0; 
	for(int i=0; i<=25; i++) {
		if(t[0][i]) { //如果当前边存在 
			q.push(t[0][i]); //节点入队 
		}
	}
	
	while(!q.empty()) {
		int u = q.front(); //取出队首元素 
		q.pop();
		
		//遍历所有出边 
		for(int i=0; i<=25; i++) {
			int v = t[u][i];
			if(v) { //如果存在节点 
				ne[v] = t[ne[u]][i];//创建子结点得回跳边
				q.push(v); //子结点入队 
			} else {
				t[u][i] = t[ne[u]][i]; //子结点不存在，创建当前节点得转移边 
			} 
		}
	}
}

//根据创建的自动机，主串s进行查询 
int query(string s) {
	int ans = 0;
	for(int i=0, p=0; i<s.size(); i++) { //i:枚举主串的每一个字符，p：当前访问的字典树编号 
	 	p = t[p][s[i]-'a']; //跳到树边或转移边
	 	
	 	for(int j=p; j&&cnt[j]!=-1; j=ne[j]) {//沿着回跳边，遍历所有得最大后缀 
	 		ans += cnt[j]; //累计遇到的模式串个数 
	 		cnt[j] = -1; //避免重复计算
		}
	} 
	return ans;
}

int main() {
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>p;
		insert(p);  //模式边创建字典树 
	}
	
	build(); //创建AC自动机（添加回跳边和转移边） 
	
	cin>>s;
	cout<<query(s); //查询主字符串 

	return 0;
}

