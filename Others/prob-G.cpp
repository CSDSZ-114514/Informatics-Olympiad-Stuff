#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

typedef long long ll;

const ll MAX = 500005;

// ans 数组用于模拟二进制加法后的和
char ans[MAX + 2];

void sol() {
    ll n;
    if (!(cin >> n)) return; 
    string s;
    if (!(cin >> s)) return;

    ll p = -1; // p: 第一个 '1' 的位置
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            p = i;
            break;
        }
    }

    if (p == -1) {
        cout << 0 << "\n";
        return;
    }
    
    // 1. 构造子序列 A 和 B 的位串 (res_a, res_b)
    // 这里的 res_a 和 res_b 是划分 S 后的位串，非补齐的子序列
    string res_a = "", res_b = ""; 
    ll lna = 0, lnb = 0;
    bool assigned_a = false; // 是否已经将 S[p] 分配给 A

    for (ll i = 0; i < n; ++i) {
        if (i < p) {
            // S[i]=0，分配给 B (保持 A 长度最小)
            res_a += '0'; lna++; 
            res_b += '0'; lnb++;
        } else if (i == p) {
            // 最高的 '1' 必须分配给 A (保证 A 数值较大)
            res_a += '1'; lna++;
            res_b += '0'; lnb++;
            assigned_a = true;
        } else { // i > p
            // 严格交替分配 (保证 A 和 B 的后续位产生最小进位)
            if (s[i] == '1') {
                if (assigned_a) {
                    // A 已经高位 1，后续 1 必须给 B
                    res_a += '0'; lna++;
                    res_b += '1'; lnb++;
                    assigned_a = false; // B 获得 1，现在 B 更大，下一位给 A
                } else {
                    // B 获得高位 1，后续 1 必须给 A
                    res_a += '1'; lna++;
                    res_b += '0'; lnb++;
                    assigned_a = true; // A 获得 1，现在 A 更大，下一位给 B
                }
            } else { // s[i] == '0'
                 // 0 不影响数值，分配给当前较短的序列
                if (lna <= lnb) {
                    res_a += '0'; lna++;
                } else {
                    res_b += '0'; lnb++;
                }
            }
        }
    }
    
    // 2. 补齐子序列 (res_a 和 res_b 是最终划分的序列，不需要补齐)
    // 这一步错误！res_a/res_b 应该是 S 的两个子序列，不是等长位串。

    // 重新定义 A 和 B 为真正的子序列
    string suba = "", subb = "";
    assigned_a = false;
    
    for (ll i = 0; i < n; ++i) {
        if (s[i] == '1') {
            if (!assigned_a) {
                suba += '1';
                assigned_a = true;
            } else {
                subb += '1';
            }
        } else { // s[i] == '0'
            // 0 分配给长度较短的序列
            if (suba.length() <= subb.length()) {
                suba += '0';
            } else {
                subb += '0';
            }
        }
    }
    
    // 3. 补齐并进行二进制加法 (与前一个代码相同，但现在 suba/subb 是正确的子序列)
    ll maxl = max((ll)suba.length(), (ll)subb.length());
    
    if ((ll)suba.length() < maxl) suba = string(maxl - suba.length(), '0') + suba;
    if ((ll)subb.length() < maxl) subb = string(maxl - subb.length(), '0') + subb;

    ll car = 0;
    ll k = maxl; 
    
    memset(ans, 0, sizeof(ans)); 

    for (ll i = maxl - 1; i >= 0; --i) {
        ll bita = suba[i] - '0';
        ll bitb = subb[i] - '0';
        ll sum = bita + bitb + car;
        ans[k] = (sum % 2) + '0';
        car = sum / 2;
        k--;
    }
    
    // 4. 处理最终进位
    if (car > 0) {
        ans[k] = car + '0';
    } else {
        k++; // k 回到 1
    }
    
    // 5. 移除前导零并输出
    ll beg = k;
    while (beg < maxl && ans[beg] == '0') {
        beg++;
    }

    if (beg > maxl || (beg == maxl && ans[beg] == '0')) {
        cout << 0 << "\n";
    } else {
        cout << (ans + beg) << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    if (!(cin >> t)) return 0;
    while (t--) {
        sol();
    }

    return 0;
}