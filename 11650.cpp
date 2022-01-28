#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

#define point pair<int, int>

int main()
{
    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i] = {x, y};
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
        cout << v[i].first << ' ' << v[i].second << '\n';
    return 0;
}