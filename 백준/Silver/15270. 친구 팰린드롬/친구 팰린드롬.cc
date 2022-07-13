#include <iostream>
#include <utility>
#define pii pair<int, int>

using namespace std;

bool isFriend[21][21];
int n, m;
int maxval = 0;
bool matched[21];

void func(int k, int cur)
{
    if (k >= n)
    {
        maxval = max(cur, maxval);
        return;
    }

    if (matched[k])
    {
        func(k + 1, cur);
    }

    for (int i = k + 1; i <= n; i++)
    {
        if (isFriend[i][k] && !matched[i] && !matched[k])
        {
            matched[i] = true;
            matched[k] = true;
            func(k + 1, cur + 2);
            matched[i] = false;
            matched[k] = false;
        }
    }

    func(k + 1, cur);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            isFriend[i][j] = false;
        }
        matched[i] = false;
    }

    int a, b;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        isFriend[a][b] = true;
        isFriend[b][a] = true;
    }

    func(1, 0);
    if (maxval < n)
        maxval++;

    cout << maxval;
}