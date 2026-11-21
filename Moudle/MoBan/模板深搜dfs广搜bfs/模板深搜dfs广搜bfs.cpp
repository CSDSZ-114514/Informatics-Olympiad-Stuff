#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue> 
#include<map> 
using namespace std;
struct Node{
	int x, y;
};
queue<int> q;
queue<Node> qxy;
int g[1005][1005], f[1005], fxy[1005][1005];
int n;
int dx4[4] = { -1,1,0,0 };
int dy4[4] = { 0,0,-1,1 };
int dx8[8] = { 0,1,-1,0,-1,1,-1,1 };
int dy8[8] = { 1,0,0,-1,1,1,-1,-1 };

void bfs() { //广搜
	while (!q.empty()) {
		int temp = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (g[temp][i] == 1 && f[i] == 0) {
				q.push(i);
				f[i] = 1;
			}
		}
	}
}
void bfs_xy4() { //四向广搜
	while (!q.empty()) {
		Node temp = qxy.front();
		qxy.pop();
		for (int i = 0; i <= 3; i++) {
			int tx = temp.x + dx4[i];
			int ty = temp.y + dy4[i];
			if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
				if (g[tx][ty] != 1 && fxy[tx][ty] == 0) {
					qxy.push({ tx,ty });
					fxy[tx][ty] = 1;
				}
			}
		}
	}
}
void bfs_xy4_lenth() { //四向广搜路径
	while (!q.empty()) {
		Node temp = qxy.front();
		qxy.pop();
		for (int i = 0; i <= 3; i++) {
			int tx = temp.x + dx4[i];
			int ty = temp.y + dy4[i];
			if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
				if (g[tx][ty] != 1 && fxy[tx][ty] == -1) {
					qxy.push({ tx,ty });
					fxy[tx][ty] = fxy[temp.x][temp.y] + 1;
				}
			}
		}
	}
}
void bfs_xy8() { //八向广搜
	while (!q.empty()) {
		Node temp = qxy.front();
		qxy.pop();
		for (int i = 0; i <= 7; i++) {
			int tx = temp.x + dx8[i];
			int ty = temp.y + dy8[i];
			if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
				if (g[tx][ty] != 1 && fxy[tx][ty] == 0) {
					qxy.push({ tx,ty });
					fxy[tx][ty] = 1;
				}
			}
		}
	}
}
void bfs_xy8_lenth() { //八向广搜路径
	while (!q.empty()) {
		Node temp = qxy.front();
		qxy.pop();
		for (int i = 0; i <= 7; i++) {
			int tx = temp.x + dx8[i];
			int ty = temp.y + dy8[i];
			if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
				if (g[tx][ty] != 1 && fxy[tx][ty] == -1) {
					qxy.push({ tx,ty });
					fxy[tx][ty] = fxy[temp.x][temp.y]+1;
				}
			}
		}
	}
}
void dfs(int x) { //深搜
	for (int i = 1; i <= n; i++) {
		if (g[x][i] == 1 && f[i] == 0) {
			f[i] = 1;
			dfs(i);
		}
	}
}
void dfs_xy4(int x, int y) { //四向深搜
	for (int i = 0; i <= 3; i++) {
		int tx = x + dx4[i];
		int ty = y + dy4[i];
		if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
			if (g[tx][ty] != 1 && fxy[tx][ty] == 0) {
				fxy[tx][ty] = 1;
				dfs_xy4(tx, ty);
			}
		}
	}
}
void dfs_xy4_all(int x,int y) { //四向深搜所有路径
	if (x == n && y == n) {
		return;
	}
	for (int i = 0; i <= 3; i++) {
		int tx = x + dx4[i];
		int ty = y + dy4[i];
		if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
			if (g[tx][ty] != 1 && fxy[tx][ty] == 0) {
				fxy[tx][ty] = 1;
				dfs_xy4_all(tx, ty);
				fxy[tx][ty] = 0;
			}
		}
	}
}
void dfs_xy8(int x, int y) { //八向深搜
	for (int i = 0; i <= 3; i++) {
		int tx = x + dx8[i];
		int ty = y + dy8[i];
		if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
			if (g[tx][ty] != 1 && fxy[tx][ty] == 0) {
				fxy[tx][ty] = 1;
				dfs_xy8(tx, ty);
			}
		}
	}
}
void dfs_xy8_all(int x, int y) { //八向深搜所有路径
	if (x == n && y == n) {
		return;
	}
	for (int i = 0; i <= 3; i++) {
		int tx = x + dx8[i];
		int ty = y + dy8[i];
		if (tx >= 1 && ty >= 1 && tx <= n && ty <= n) {
			if (g[tx][ty] != 1 && fxy[tx][ty] == 0) {
				fxy[tx][ty] = 1;
				dfs_xy8_all(tx, ty);
				fxy[tx][ty] = 0;
			}
		}
	}
}