#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int n, m;
bool vis[8][8];
int dx[] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};
int a[8][8];
int ans = 0;

void dfs(int x, int y, int sum)
{
    // 全部格子遍历完成，更新答案
    if (x >= n)
    {
        ans = max(ans, sum);
        return;
    }
    // 计算下一个坐标：本行没结束就y+1；否则下一行开头
    int nx, ny;
    if (y + 1 < m)
    {
        nx = x;
        ny = y + 1;
    }
    else
    {
        nx = x + 1;
        ny = 0;
    }

    // 不选
    dfs(nx, ny, sum);

    // 选
    bool ok = 1;
    _for(i, 8)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx >= 0 && tx < n && ty >= 0 && ty < m && vis[tx][ty])
        {
            ok = 0;
            break;
        }
    }
    if (ok)
    {
        vis[x][y] = 1;
        dfs(nx, ny, sum + a[x][y]);
        vis[x][y] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int _;
    cin >> _;
    while (_--)
    {
        cin >> n >> m;
        _for(i, n) _for(j, m) cin >> a[i][j];
        ans = 0;
        memset(vis, 0, sizeof(vis));
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}
