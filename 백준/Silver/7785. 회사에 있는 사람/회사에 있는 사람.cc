#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, bool> remain;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--)
    {
        string name, io;
        cin >> name >> io;
        if (remain.find(name) == remain.end())
        {
            remain.insert({name, io == "leave" ? false : true});
            continue;
        }
        remain[name] = io == "leave" ? false : true;
    }

    vector<string> ans;

    for (auto i : remain)
    {
        if (i.second)
            ans.push_back(i.first);
    }
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());

    for (string i : ans)
        cout << i << '\n';
}