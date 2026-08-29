#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
const int maxn = 1005;
bool a[maxn][maxn];
int ship[maxn][maxn];
int lx[maxn * maxn];
int ly[maxn * maxn];
int rx[maxn * maxn];
int ry[maxn * maxn];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int r, c;
void dfs(int x, int y)
{
    int id = ship[x][y];
    lx[id] = min(lx[id], x);
    ly[id] = min(ly[id], y);
    rx[id] = max(rx[id], x);
    ry[id] = max(ry[id], y);
    _for(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && nx < r && ny >= 0 && ny < c && !ship[nx][ny] && a[nx][ny])
        {
            ship[nx][ny] = id;
            dfs(nx, ny);
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    memset(lx, 0xff, sizeof(lx));
    memset(ly, 0xff, sizeof(ly));
    cin >> r >> c;
    _for(i, r) _for(j, c)
    {
        char ch;
        cin >> ch;
        a[i][j] = (ch == '#');
    }
    int cnt = 1;
    _for(i, r) _for(j, c)
    {
        if (a[i][j] && !ship[i][j])
        {
            lx[cnt] = rx[cnt] = i;
            ly[cnt] = ry[cnt] = j;
            ship[i][j] = (cnt++);
            dfs(i, j);
        }
    }
    _rep(i, 1, cnt) _rep(j, lx[i], rx[i] + 1) _rep(k, ly[i], ry[i] + 1) if (!ship[j][k])
    {
        cout << "Bad placement." << endl;
        return 0;
    }
    cout << "There are " << cnt - 1 << " ships." << endl;
}