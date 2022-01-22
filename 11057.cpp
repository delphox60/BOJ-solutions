#include <iostream>
#include <vector>

#define ll long long

using namespace std;

vector<vector<ll>> nums(10, vector<ll>(1005, 0));

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    for (int i = 0; i < 10; i++)
        nums[i][1] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int idx = 0; idx < 10; idx++)
        {
            for (int next_idx = idx; next_idx < 10; next_idx++)
            {
                nums[next_idx][i + 1] += nums[idx][i];
                nums[next_idx][i + 1] %= 10007;
            }
        }
    }

    ll total = 0;
    for (int i = 0; i < 10; i++)
        total += nums[i][n];
    cout << total % 10007 << '\n';
}