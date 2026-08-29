#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int ans = 0;
bool b[105][105];
int n, m;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
void dfs(int x, int y)
{
    if (!b[x][y])
        return;
    b[x][y] = 0;
    _for(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= n || nx < 0 || ny >= m || ny < 0)
            continue;
        dfs(nx, ny);
    }
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
        b[i][j] = c - '0';
    }
    _for(i, n) _for(j, m)
    {
        ans += b[i][j];
        dfs(i, j);
    }
    cout << ans << endl;
}