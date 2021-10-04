#include <iostream>
#include <deque>
#include <string>

int main()
{
    using namespace std;
    deque<int> deq;
    string command;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> command;
        if (command == "push_front")
        {
            int x;
            cin >> x;
            deq.push_front(x);
        }
        if (command == "push_back")
        {
            int x;
            cin >> x;
            deq.push_back(x);
        }
        if (command == "pop_front")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
            {
                int y = deq.front();
                cout << y << "\n";
                deq.pop_front();
            }
        }
        if (command == "pop_back")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
            {
                int y = deq.back();
                cout << y << "\n";
                deq.pop_back();
            }
        }
        if (command == "size")
        {
            int y = deq.size();
            cout << y << "\n";
        }
        if (command == "empty")
        {
            int y = deq.empty();
            cout << y << '\n';
        }
        if (command == "front")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
            {
                int y = deq.front();
                cout << y << "\n";
            }
        }
        if (command == "back")
        {
            if (deq.empty())
                cout << -1 << "\n";
            else
            {
                int y = deq.back();
                cout << y << "\n";
            }
        }
    }
    return 0;
}