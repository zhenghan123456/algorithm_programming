#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int dx[] = {1, 2, 1, 2};
int dy[] = {2, 1, -2, -1};
int b[20][20];
// 永远往右走所以不用vis
int n, m;
int dfs(int x, int y)
{
    int ans = 0;
    if (x == m - 1 && y == n - 1)
        return 1;
    _for(i, 4)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || nx >= m)
            continue;
        if (ny < 0 || ny >= n)
            continue;
        ans += dfs(nx, ny);
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    n++;
    m++; // 这道题出的很细，n和m都要+1
    cout << dfs(0, 0) << endl;
}