#include <iostream>

using namespace std;

int arr[100005];

long long histogram(int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;

    long long maxValue = max(histogram(low, mid), histogram(mid + 1, high));

    int rdx = mid + 1;
    int ldx = mid - 1;
    long long result = arr[mid];
    int height = arr[mid];
    int width = 1;

    while (rdx <= high || ldx >= low)
    {
        if (arr[rdx] >= arr[ldx])
        {
            height = min(height, arr[rdx]);
            width++;
            result = max(result, (long long)height * width);
            rdx++;
        }

        else if (arr[rdx] < arr[ldx])
        {
            height = min(height, arr[ldx]);
            width++;
            result = max(result, (long long)height * width);
            ldx--;
        }

        if (rdx > high || ldx < low)
            break;
    }
    while (rdx <= high)
    {
        height = min(height, arr[rdx]);
        width++;
        result = max(result, (long long)height * width);
        rdx++;
        if (rdx > high)
            break;
    }
    while (ldx >= low)
    {
        height = min(height, arr[ldx]);
        width++;
        result = max(result, (long long)height * width);
        ldx--;
        if (ldx < low)
            break;
    }
    maxValue = max(maxValue, result);

    return maxValue;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    cout << histogram(1, N) << "\n";

    // for (int i = 99909; i <= 100000; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //         arr[j] = i;
    //     cout << histogram(1, i) << "\n";
    // }
    return 0;
}