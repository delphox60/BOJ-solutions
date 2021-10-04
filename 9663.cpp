#include <iostream>
#include <utility>

using namespace std;

bool cond1[15];
bool cond2[29];
bool cond3[29];

int count_var = 0;

void func(int k, int n)
{
    if (k == n)
    {
        count_var++;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (cond1[i] && cond2[k + i] && cond3[k - i + n - 1])
        {
            cond1[i] = false;
            cond2[k + i] = false;
            cond3[k - i + n - 1] = false;

            func(k + 1, n);

            cond1[i] = true;
            cond2[k + i] = true;
            cond3[k - i + n - 1] = true;
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 15; i++)
    {
        cond1[i] = true;
        cond2[i] = true;
        cond3[i] = true;
        cond2[i + 14] = true;
        cond3[i + 14] = true;
    }

    int n;
    cin >> n;

    func(0, n);

    cout << count_var << "\n";
    return 0;
}