#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define _for(i, n) for (int i = 0; i < n; i++)
#define _rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
int sticks[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int n;
int arr[3];
int sticknum(int n)
{
    int res = 0;
    do
    {
        res += sticks[n % 10];
        n /= 10;
    } while (n);
    return res;
}

int ans = 0;
// 可以使用循环代替
void dfs(int sum, int pos)
{
    if (sum > n)
        return; // 剪枝
    if (pos == 3)
    {
        ans += ((sum == n) && (arr[0] + arr[1] == arr[2]));
        return;
    }
    _for(i, 1000)
    {
        arr[pos] = i;
        dfs(sum + sticknum(i), pos + 1);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    n -= 4;
    dfs(0, 0);
    cout << ans << endl;
}