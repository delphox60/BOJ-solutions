#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        map<string, int> closet;

        int n;
        cin >> n;

        while (n--)
        {
            string item, cate;
            cin >> item >> cate;
            if (closet.find(cate) == closet.end())
                closet.insert(make_pair(cate, 1));
            else
                closet[cate]++;
        }

        int res = 1;
        for (auto i : closet)
        {
            res *= (i.second + 1);
        }
        res--;
        cout << res << '\n';
    }
}