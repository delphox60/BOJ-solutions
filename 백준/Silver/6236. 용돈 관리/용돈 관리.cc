#include <iostream>
#include <algorithm>
#define MAXVAL 100000

using namespace std;

int n, m;
int cash[MAXVAL];

bool func(int mid)
{

    int num = 1;

    int sum = mid;

    for (int i = 0; i < n; i++)
    {

        if (mid < cash[i])
            return false;

        if (sum - cash[i] < 0)
        {
            sum = mid;
            num++;
        }

        sum -= cash[i];
    }

    return m >= num;
}

int main(void)

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    cin >> n >> m;

    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> cash[i];
        sum += cash[i];
    }

    int low = 1, high = sum;

    int result = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (func(mid))
        {
            result = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    cout << result << "\n";
}