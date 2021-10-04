#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    int k;
    cin >> N >> k;

    int girls[6];
    int boys[6];

    for (int i = 0; i < 6; i++)
    {
        girls[i] = 0;
        boys[i] = 0;
    }

    int gender;
    int grade;

    for (int i = 0; i < N; i++)
    {
        cin >> gender >> grade;

        if (gender)
            boys[grade - 1]++;
        else
            girls[grade - 1]++;
    }

    int result = 0;
    for (int i = 0; i < 6; i++)
    {
        result += boys[i] / k;
        result += girls[i] / k;
        if (boys[i] % k)
            result++;
        if (girls[i] % k)
            result++;
    }
    cout << result << '\n';
    return 0;
}