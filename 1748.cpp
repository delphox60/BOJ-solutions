#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    long long tmp;
    long long result = 0;

    cin >> n;

    long long divider = 10;
    long long length = 1;

    while (n >= divider)
    {
        result += (divider - (divider / 10 - 1) - 1) * length;
        divider *= 10;
        length++;
    }
    result += (n - (divider / 10 - 1)) * length;
    cout << result << '\n';
    return 0;
}