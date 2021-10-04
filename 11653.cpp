#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int cur = n;

    for (int i = 2; i <= n; i++)
    {
        while (cur % i == 0)
        {
            cur /= i;
            cout << i << "\n";
        }
    }
    return 0;
}