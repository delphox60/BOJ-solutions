#include <iostream>
#include <climits>
#define ll long long

using namespace std;

int arr[12];
int op[4];
int n;
ll maxval = 10000000000000000000;
ll minval = -10000000000000000000;

void func(int k = 1, ll cur = arr[0])
{
    if (k == n)
    {
        maxval = max(maxval, cur);
        minval = min(minval, cur);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (op[i] == 0)
            continue;
        ll tmp = cur;
        switch (i)
        {
        case 0:
        {
            tmp += arr[k];
            break;
        }
        case 1:
        {
            tmp -= arr[k];
            break;
        }
        case 2:
        {
            tmp *= arr[k];
            break;
        }
        case 3:
        {
            tmp /= arr[k];
            break;
        }
        default:
            break;
        }

        op[i]--;
        func(k + 1, tmp);
        op[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < 4; i++)
        cin >> op[i];

    func();

    cout << maxval << '\n';
    cout << minval << '\n';
}