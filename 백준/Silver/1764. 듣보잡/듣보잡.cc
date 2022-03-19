#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, bool> d;
map<string, bool> b;
vector<string> res;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    while (n--)
    {
        string dname;
        cin >> dname;
        d.insert({dname, true});
    }

    while (m--)
    {
        string bname;
        cin >> bname;
        b.insert({bname, true});
    }
    int cnt = 0;
    for (auto i : d)
    {
        if (b.find(i.first) != b.end())
        {
            cnt++;
            res.push_back(i.first);
        }
    }

    sort(res.begin(), res.end());

    cout << cnt << '\n';
    for (string i : res)
        cout << i << '\n';
}