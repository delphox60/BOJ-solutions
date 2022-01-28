#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a(1001, 0);
vector<int> d(1001, 0);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    d[1] = a[1] * n;

    for (int i = 2; i <= n; i++)
        for (int j = n / i; n - i * j < i; j--)
        {
            d[i] = max(d[i], a[i] * j + d[n - i * j]);
        }

    cout << *max_element(d.begin(), d.end()) << '\n';

    for (int i = 1; i <= n; i++)
        cout << d[i] << ' ';
}