#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int result = 0;

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int cur = i;
        while (cur % 5 == 0)
        {
            cur /= 5;
            result++;
        }
    }
    cout << result << "\n";
    return 0;
}