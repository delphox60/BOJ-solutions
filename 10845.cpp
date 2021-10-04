#include <iostream>
#include <queue>
#include <string>

int main()
{
    using namespace std;
    int n;
    queue<int> que;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string command;
        cin >> command;
        if (command == "push")
        {
            int x;
            cin >> x;
            que.push(x);
        }
        if (command == "pop")
        {
            if (que.empty())
                cout << -1 << "\n";
            else
            {
                int y = que.front();
                cout << y << "\n";
                que.pop();
            }
        }
        if (command == "size")
        {
            if (que.empty())
                cout << 0 << "\n";
            else
            {
                int y = que.size();
                cout << y << "\n";
            }
        }
        if (command == "empty")
        {
            int y = que.empty();
            cout << y << "\n";
        }
        if (command == "front")
        {
            if (que.empty())
                cout << -1 << "\n";
            else
            {
                int y = que.front();
                cout << y << "\n";
            }
        }
        if (command == "back")
        {
            if (que.empty())
                cout << -1 << "\n";
            else
            {
                int y = que.back();
                cout << y << "\n";
            }
        }
    }
    return 0;
}