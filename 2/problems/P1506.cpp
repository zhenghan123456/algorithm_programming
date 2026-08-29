#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 510;
bool mp[maxn][maxn];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n, m;
void dfs(int x, int y)
{
    if (mp[x][y])
        return;
    mp[x][y] = 1;
    _for(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
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
        mp[i][j] = (c == '*');
    }
    int cnt = 0;
    // 四周的点都需要考虑一下
    _for(i, n)
    {
        dfs(i, 0);
        dfs(i, m - 1);
    }
    _rep(i, 1, m - 1)
    {
        dfs(0, i);
        dfs(n - 1, i);
    }
    _for(i, n) _for(j, m) if (!mp[i][j]) cnt++;
    cout << cnt << endl;
}