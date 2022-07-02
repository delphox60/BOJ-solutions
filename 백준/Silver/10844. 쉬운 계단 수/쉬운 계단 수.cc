#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>> num_stair(10, vector<long long>(101, 0));

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;

    for (long long i = 1; i < 10; i++)
    {
        num_stair[i][1] = 1;
    }

    for (long long i = 1; i < n; i++)
    {
        for (long long j = 0; j < 10; j++)
        {
            if (num_stair[j][i])
            {
                if (j - 1 >= 0)
                {
                    num_stair[j - 1][i + 1] += num_stair[j][i];
                    num_stair[j - 1][i + 1] %= 1000000000;
                }
                if (j + 1 <= 9)
                {
                    num_stair[j + 1][i + 1] += num_stair[j][i];
                    num_stair[j + 1][i + 1] %= 1000000000;
                }
            }
        }
    }

    long long total = 0;
    for (int i = 0; i < 10; i++)
    {
        total += num_stair[i][n];
    }
    cout << total % 1000000000 << '\n';
}