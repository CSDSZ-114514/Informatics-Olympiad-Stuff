#include<bits/stdc++.h>
using namespace std;

typedef int INT;
#define int long long
typedef vector<int> Vec;
typedef vector<bool> Set;

const int N = 8010;
const int H = 810;

int n;
int h;
int ans;
int fa[N];
int S[N];
vector<Vec> son(0);

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

void Add(int f, int s){
	fa[s] = f;
	son[f].push_back(s);
}

void Merge(Set &s1, const Set s2){
	for(int i = 0; i <= n+1; i ++){
		s1[i] = s1[i] || s2[i];
	}
}

pair<int, Set> Mex(int i){
	Set s(n+2, false);
	s[S[i]] = true;
	int sum = 0;
	for(int j = 0; j < son[i].size(); j ++){
		pair<int, Set> pis = Mex(son[i][j]);
		sum += pis.first;
		Merge(s, pis.second);
		//printf("(%lld) %lld: %lld\n", i, son[i][j], pis.first);
	}
	int p = 0;
	while(p <= h && s[p]){
		p ++;
	}
	sum += p;
	return make_pair(sum, s);
}

void Try(int i){
	int old = S[i];
	for(int j = ((i == 1) ? n+1 : S[fa[i]]); j >= 0; j --){
		S[i] = j;
		if(son[i].empty()){
			pair<int, Set> pis = Mex(1);
			ans = max(ans, pis.first);
		}else{
			for(int k = 0; k < son[i].size(); k ++){
				Try(son[i][k]);
			}
		}
	}
	S[i] = old;
}

int Solve(){
	n = read();
	h = read();
	son = vector<Vec>(n+1, Vec(0));
	memset(S, 0, sizeof(S));
	for(int i = 2; i <= n; i ++){
		Add(read(), i);
	}
	ans = 0;
	Try(1);
	return ans;
}

INT main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	int T;
	T = read();
	while(T --){
		printf("%lld\n", Solve());
	}
	return 0;
}
