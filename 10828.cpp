#include <iostream>
#include <string>
#include <stack>

int main()
{
    using namespace std;

    int n;
    cin >> n;
    stack<int> stk;

    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int x;
            cin >> x;
            stk.push(x);
        }
        if (command == "pop")
        {
            if (stk.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                int y = stk.top();
                cout << y << endl;
                stk.pop();
            }
        }
        if (command == "size")
        {
            int y = stk.size();
            cout << y << endl;
        }
        if (command == "empty")
        {
            int y = stk.empty();
            cout << y << endl;
        }
        if (command == "top")
        {
            if (stk.empty())
            {
                cout << -1 << endl;
            }
            else
            {
                int y = stk.top();
                cout << y << endl;
            }
        }
    }
    return 0;
}