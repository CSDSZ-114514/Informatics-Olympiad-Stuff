
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll N = 100099;
//ll MOD_ = 1;
ll n, q, a[N];

void pow64ofmod(){
	//for(int i = 1;i <= 63;i++){
		//MOD_ *= (ll)(2);
	//}
}

struct segemnt_tree_max{
	ll seg_[4 * N], lazy[4 * N];
	
	void pushup(int p){
		seg_[p] = max(seg_[p * 2], seg_[p * 2 + 1]);
	}
	void pushdown(int p){
		seg_[p] = max(lazy[p], seg_[p]);
		lazy[p * 2 + 1] = max(lazy[p * 2 + 1], lazy[p]);
		lazy[p * 2] = max(lazy[p * 2], lazy[p]);
		lazy[p] = seg_[p];
	}
	void build(int p, int l, int r){
		lazy[p] = -1e9;
		if(l == r){
			seg_[p] = -1e9;
			return ;
		}
		int mid = (l + r) / 2;
		build(p * 2, l, mid);
		build(p * 2 + 1, mid + 1, r);
		pushup(p);
	}
	
	ll query(int p, int l, int r, int ql, int qr){
		pushdown(p);
		if(l >= ql && r <= qr){
			return seg_[p];
		} 
		if(l > qr || r < ql){
			return -1e9;
		}
		int mid = (l + r) / 2;
		return max(query(p * 2, l, mid, ql, qr), query(p * 2 + 1, mid + 1, r, ql, qr));
	}
	
	void update(int p, int l, int r, int dl, int dr, ll d){
		pushdown(p);
		if(l >= dl && r <= dr){
			lazy[p] = max(lazy[p], d);
			return ;
		} 
		if(l > dr || r < dl){
			return ;
		}
		int mid = (l + r) / 2;
		update(p * 2, l, mid, dl, dr, d);
		update(p * 2 + 1, mid + 1, r, dl, dr, d);
	}
}segmax;

void out_num(){
	ll res = segmax.query(1, 1, n, 1, 1);
	for(int i = 2;i <= n;i++){
		//printf("the perfect of %d = %d\n", i, segmax.query(1, 1, n, i, i));
		ll queryofmax = segmax.query(1, 1, n, i, i); // % MOD_
		//if(queryofmax < 0) queryofmax += MOD_;
		res ^= (i * queryofmax);
	}
	if(res < 0){
		// still wrong
		//18446744073709551616
		res = -1 * res;
		string MOD_ = "18446744073709551616";
		string dele = "";
		while(res > 0){
			int d = res % 10;
			dele = (char)((int)('0') + d) + dele;
			res /= 10;
		}
		int poi1 = MOD_.length() - 1, poi2 = dele.length() - 1;
		while(poi2 != -1){
			if((int)MOD_[poi1] < (int)dele[poi2]){
				if(MOD_[poi1 - 1] != '0'){
					MOD_[poi1 - 1] = (char)((int)MOD_[poi1 - 1] - 1);
				} else{
					MOD_[poi1 - 2] = (char)((int)MOD_[poi1 - 2] - 1);
					MOD_[poi1 - 1] = '9';
				}
				MOD_[poi1] = (char)((int)(MOD_[poi1] - '0') + 10 - (int)(dele[poi2] - '0') + '0');
			} else{
				MOD_[poi1] = (char)((int)(MOD_[poi1] - '0') - (int)(dele[poi2] - '0') + '0');
			}
			poi1--;
			poi2--;
		}
		int zerofront = true;
		for(int i = 0;i <= MOD_.length() - 1;i++){
			if(zerofront && MOD_[i] == '0') continue;
			if(zerofront) zerofront = false;
			cout << MOD_[i];
		}
		cout << endl;
		return ;
	} 
	cout << res << endl;
	return ;
}

int main(){
	freopen("query.in", "r", stdin);
	freopen("query.out", "w", stdout);
	pow64ofmod();
	//cout << MOD_ << " pgdk\n";
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		a[i] += a[i - 1]; 
	}
	//cout << "outbuild seg\n";
	cin >> q;
	while(q--){
		int l, r;
		cin >> l >> r;
		segmax.build(1, 1, n);
		//cout << "outbuild segmax\n";
		if(l == -1){
			for(int i = 1;i <= n - l + 1;i++){
				ll segq = a[i + l - 1] - a[i - 1];
				segmax.update(1, 1, n, i, i + l - 1, segq);
			}
			out_num();
		} else{
			for(int i = l;i <= r;i++){
				for(int j = 1;j <= n - i + 1;j++){
					ll segq = a[j + i - 1] - a[j - 1];
					//printf("[%d, %d] the sigma = %d\n", j, j + i - 1, segq);
					//cout << "query\n";
					segmax.update(1, 1, n, j, j + i - 1, segq);
					//cout << "update\n";
				}
			}
			out_num();
		}
	}
	return 0;
}













