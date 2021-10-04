#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);

    cin.tie(0);

    int zero[45];
    int one[45];
    zero[0] = 1;
    zero[1] = 0;
    one[0] = 0;
    one[1] = 1;
    for (int i = 2; i <= 41; i++)
    {
        zero[i] = zero[i - 1] + zero[i - 2];
        one[i] = one[i - 1] + one[i - 2];
    }

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        cout << zero[m] << " " << one[m] << "\n";
    }
    return 0;
}