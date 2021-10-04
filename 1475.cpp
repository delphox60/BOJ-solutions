#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string num;
    cin >> num;

    int nums[10];

    for (int i = 0; i < 10; i++)
        nums[i] = 0;

    for (int i = 0; i < num.length(); i++)
    {
        nums[(int)num[i] - 48]++;
    }

    int sixNine = nums[6] + nums[9];
    sixNine /= 2;
    if ((nums[6] + nums[9]) % 2)
        sixNine++;
    nums[6] = sixNine;

    int max = 0;
    for (int i = 0; i < 9; i++)
    {
        if (max < nums[i])
            max = nums[i];
    }
    cout << max << '\n';
    return 0;
}