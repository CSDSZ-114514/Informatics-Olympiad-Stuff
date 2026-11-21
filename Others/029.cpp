#include <iostream>
using namespace std;

int r, s;
bool f[30][30];
char c[30][30];
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, -1, 1, 0, 0};
bool box[130];
int maxn = 1;

void dfs(int x, int y, int cnt)
{
	      for (int i = 1; i <= 4; i++)
	      {
		            int tx = x + dx[i];
		            int ty = y + dy[i];
		            if (tx >= 1 && tx <= r && ty >= 1 && ty <= s)
		            {
			                  if (!box[c[tx][ty]])
			                  {
				                        box[c[tx][ty]] = true;
				                        maxn = max(cnt + 1, maxn);
				                        dfs(tx, ty, cnt + 1);
				                        box[c[tx][ty]] = false;
				                        
			                  }
		            }
	      }
}

int main()
{
	      cin >> r >> s;
	      for (int i = 1; i <= r; i++)
	      {
		            for (int j = 1; j <= s; j++)
		            {
			                  cin >> c[i][j];
		            }
	      }
	      box[c[1][1]] = true;
	      dfs(1, 1, 1);
	      cout << maxn;
	      return 0;
}
