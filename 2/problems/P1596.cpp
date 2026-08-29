#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int n, m;
const int maxn = 105;
bool a[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
bool dfs(int x, int y)
{
    if (vis[x][y] || !a[x][y])
        return 0;
    // 打标记
    vis[x][y] = 1;
    _for(i, 8)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= m || ny < 0)
            continue;
        dfs(nx, ny);
    }
    return 1; // 已经检验过了所以直接返回1
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    _for(i, n) _for(j, m)
    {
        char c;
        cin >> c;
        a[i][j] = (c == 'W');
    }
    int ans = 0;
    _for(i, n) _for(j, m) if (dfs(i, j)) ans++;
    cout << ans << endl;
}