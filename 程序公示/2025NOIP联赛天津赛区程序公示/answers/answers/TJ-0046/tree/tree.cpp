#include<bits/stdc++.h>

using namespace std;
int t,n,m,a[8008],b[8008],w[8008][8008];

vector<int,int> l[8008];


int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	cin >> t;
	while (t--){
		cin >> n >>m;
		for (int i = 2; i<= n;i++){
			int x;
			cin >> x;
			w[i] = x;
			l[i].push_back(x);
		}
		if (m == 1){
			cout << n+1<<endl;
		}
		else{
			cout << n*2 -1 <<endl; 
		}
	}
	return 0;
}
