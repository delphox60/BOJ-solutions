#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;
    cin >> n;
    long long tmp = n;
    long long result = 0;

    for (long long i = n; i > 0; i--)
    {
        long long rem = tmp / (i * i);
        tmp %= (i * i);
        cout << tmp << endl;
        result += rem;
    }
    cout << result << '\n';
}