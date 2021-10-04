#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
    return a.first < b.first;
}

int main()
{

    int n;
    cin >> n;
    vector<pair<int, string>> list;
    for (int i = 0; i < n; i++)
    {
        int x;
        string y;
        cin >> x;
        cin >> y;
        list.push_back(pair<int, string>(x, y));
    }
    stable_sort(list.begin(), list.end(), compare);
    for (int i = 0; i < n; i++)
    {
        cout << list[i].first << " " << list[i].second << "\n";
    }
    return 0;
}