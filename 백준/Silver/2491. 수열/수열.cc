#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100000];
int inc[100000];
int desc[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    inc[0] = 1;
    desc[0] = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] >= arr[i - 1])
        {
            inc[i] = inc[i - 1] + 1;
        }
        else
        {
            inc[i] = 1;
        }
        if (arr[i] <= arr[i - 1])
        {
            desc[i] = desc[i - 1] + 1;
        }
        else
        {
            desc[i] = 1;
        }
    }

    cout << max(*max_element(inc, inc + n), *max_element(desc, desc + n));
}