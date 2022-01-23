#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> v(1000);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.begin() + n);
    for (auto it = v.begin(); it != v.begin() + n; it++)
        cout << *it << '\n';
}