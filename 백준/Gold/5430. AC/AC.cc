#include <iostream>
#include <string>
#include <deque>

using namespace std;

deque<string> dq;

void insert(string ip)
{
    string cur = "";
    for (char c : ip)
    {
        if (c == ',' || c == ']')
        {
            if (cur != "")
                dq.push_back(cur);
            cur = "";
        }
        else if (c == '[')
            cur = "";
        else
            cur += c;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        while (!dq.empty())
            dq.pop_back();
        string e, list;
        int n;
        bool reversed = false;
        bool error = false;

        cin >> e >> n >> list;

        insert(list);

        for (char cmd : e)
        {
            if (cmd == 'R')
                reversed = !reversed;
            if (cmd == 'D')
            {
                if (dq.empty())
                {
                    cout << "error\n";
                    error = true;
                    break;
                }
                if (reversed)
                {
                    dq.pop_back();
                    continue;
                }
                dq.pop_front();
            }
        }
        if (error)
            continue;
        if (dq.empty())
        {
            cout << "[]\n";
            continue;
        }
        cout << '[';
        if (reversed)
        {
            cout << dq.back();
            dq.pop_back();
            while (!dq.empty())
            {
                cout << ',';
                cout << dq.back();
                dq.pop_back();
            }
        }
        else
        {
            cout << dq.front();
            dq.pop_front();
            while (!dq.empty())
            {
                cout << ',';
                cout << dq.front();
                dq.pop_front();
            }
        }
        cout << "]\n";
    }
}