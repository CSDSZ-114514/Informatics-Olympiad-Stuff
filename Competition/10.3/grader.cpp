#include <bits/stdc++.h>
using namespace std;

// ===== 交互库内部状态 =====
static int n;
static vector<string> maze; // maze[i][j] = '0' 路, '1' 障碍
static int cur_x, cur_y;   // 当前坐标 (1-based)
static long long call_count = 0;
const long long MAX_CALLS = 500000;

// ===== 交互函数 =====
extern "C" bool move_to(char position) {
    if (++call_count > MAX_CALLS) {
        fprintf(stderr, "Too many move_to calls!\n");
        exit(1);
    }
    int nx = cur_x, ny = cur_y;
    switch (position) {
        case 'W': nx--; break;
        case 'A': ny--; break;
        case 'S': nx++; break;
        case 'D': ny++; break;
        default: return false;
    }
    if (nx < 1 || nx > n || ny < 1 || ny > n) return false;
    if (maze[nx][ny] == '1') return false;
    cur_x = nx; cur_y = ny;
    return true;
}

// ===== 选手函数声明 =====
extern "C" string find_out_map(int x,int y,int n);

// ===== 主函数：读取地图并运行选手程序 =====
int main() {
    // 输入格式：第一行 n，接下来 n 行地图，最后一行起点 x y
    cin >> n;
    maze.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        string row;
        cin >> row;
        maze[i] = " " + row; // 1-based
    }
    int sx, sy;
    cin >> sx >> sy;
    cur_x = sx;
    cur_y = sy;
    
    string result = find_out_map(sx, sy, n);
    
    // 验证结果
    string expected;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            expected.push_back(maze[i][j]);
    
    if (result == expected) {
        printf("Accepted! Calls: %lld\n", call_count);
    } else {
        printf("Wrong Answer!\n");
        printf("Expected: %s\n", expected.c_str());
        printf("Got:      %s\n", result.c_str());
    }
    return 0;
}
