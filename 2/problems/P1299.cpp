#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
bool col[15];
int row[15];
bool rright[30]; // 往左斜
bool lleft[30];  // 往右斜
int n;
int cnt = 0;

int dfs(int depth)
{
    int ans = 0;
    if (depth == n)
    {
        if (cnt < 3)
        {
            for (int i = 0; i < n; i++)
            {
                cout << row[i] + 1 << ' ';
            }
            cout << endl;
            cnt++;
        }
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (rright[depth - i + n] || lleft[depth + i] || col[i])
        {
            continue;
        }
        rright[depth - i + n] = lleft[depth + i] = col[i] = true;
        row[depth] = i;
        ans += dfs(depth + 1);
        rright[depth - i + n] = lleft[depth + i] = col[i] = false;
        row[depth] = 0;
    }
    return ans;
}

int main()
{
    cin >> n;
    cout << dfs(0) << endl;
}