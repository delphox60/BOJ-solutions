#include <iostream>
#include <utility>
#include <stack>
#define pii pair<int, int>

using namespace std;
stack<pii> s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, a, t;
    bool todo;

    cin >> n;

    int result = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> todo;

        if (!todo)
        {
            if (s.empty())
                continue;
            pii tmp = s.top();
            s.pop();
            tmp.second--;
            if (tmp.second == 0)
                result += tmp.first;
            else
                s.push(tmp);
            continue;
        }

        cin >> a >> t;
        if (t - 1 <= 0)
            result += a;
        else
            s.push({a, t - 1});
    }

    cout << result << endl;
}