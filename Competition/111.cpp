#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

typedef long double db;
const db EPS = 1e-15;
const db a = 10.0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cout << fixed << setprecision(8);
    cout << "设定参数: a = " << a << "\n\n";

    db L = a / 16.0 + EPS;
    db R = a / 10.0 - EPS; // 正确上限：1.0
    
    cout << "合法遍历区间: t ∈ (" << (double)L << ", " << (double)R << ")\n";
    
    db max_e = 0.0;
    db best_t = 0.0;
    db step = 1e-7; 
    
    for (db t = L; t <= R; t += step) {
        db QF1 = 8.0 * t;
        db QF2 = 32.0 * t - 2.0 * a;
        db F2P = 2.0 * a - 17.0 * t;
        
        // OIER 的严谨性：确保所有线段长度为正，否则跳过
        if (QF1 <= 0 || QF2 <= 0 || F2P <= 0) continue; 
        
        db c2 = (QF1 * QF1 + QF2 * QF2) / 4.0;
        db e2 = c2 / (a * a);
        db e = sqrt(e2);
        
        if (e > max_e) {
            max_e = e;
            best_t = t;
        }
    }

    cout << "最佳 t 坐标 = " << (double)best_t << "\n";
    cout << "搜索到的真实最大离心率 = " << (double)max_e << "\n\n";

    db theory_max = sqrt(13.0) / 5.0;
    db error_max = sqrt(2.0) / 2.0;

    cout << "理论真实上限 (sqrt(13)/5): " << (double)theory_max << "\n";
    cout << "解析错误上限 (sqrt(2)/2) : " << (double)error_max << "\n\n";

    if (max_e > error_max) {
        cout << ">> [打假成功] 实际极值大于解析给出的错误界限！\n";
        cout << ">> 答案就是 A！\n";
    }
    
    return 0;
}
