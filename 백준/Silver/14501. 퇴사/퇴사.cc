#include <iostream>

using namespace std;

int cost[16];
int pay[16];
int n;
int maxval = 0;

void func(int k, int cur)
{
    if (k == n)
    {
        maxval = max(maxval, cur);
        return;
    }

    func(k + 1, cur);
    if (k + cost[k] <= n)
        func(k + cost[k], cur + pay[k]);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> cost[i];
        cin >> pay[i];
    }
    func(0, 0);
    cout << maxval;
}