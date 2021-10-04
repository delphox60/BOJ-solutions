#include <iostream>

using namespace std;

int arr[100005];

long long acc(int i, int j)
{
    long long result = 0;
    int min = 1000005;
    for (int k = i; k <= j; k++)
    {
        result += arr[k];
        if (arr[k] < min)
            min = arr[k];
    }
    result *= min;
    return result;
}

long long dq(int low, int high)
{
    if (low == high)
        return (long long)arr[low] * arr[low];

    if (low == high - 1)
        return max((long long)max((long long)arr[low] * (long long)arr[low], (long long)arr[high] * (long long)arr[high]), acc(low, high));

    int mid = (high + low) / 2;
    long long result = max(dq(low, mid), dq(mid + 1, high));

    long long maxval = acc(mid, mid);
    int minval = arr[mid];
    long long cur = maxval;
    int rdx = mid;
    int ldx = mid;

    while (true)
    {
        if ((arr[rdx + 1] >= arr[ldx - 1] && rdx < high) || low == ldx)
        {
            rdx++;
            if (minval > arr[rdx])
            {
                cur /= minval;
                minval = arr[rdx];
                cur += arr[rdx];
                cur *= minval;
            }
            else
            {
                cur += ((long long)arr[rdx] * (long long)minval);
            }
        }

        else
        {
            ldx--;
            if (minval > arr[ldx])
            {
                cur /= minval;
                minval = arr[ldx];
                cur += arr[ldx];
                cur *= minval;
            }
            else
            {
                cur += ((long long)arr[ldx] * minval);
            }
        }

        maxval = max(cur, maxval);

        if (high == rdx && ldx == low)
            break;
    }

    result = max(result, maxval);

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << dq(0, n - 1) << "\n";

    return 0;
}
