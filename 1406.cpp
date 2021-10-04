#include <string>
#include <list>
#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string str;
    cin >> str;

    int n_cmd;
    cin >> n_cmd;

    list<char> text;

    for (int i = 0; i < str.length(); i++)
    {
        text.push_back(str[i]);
    }

    list<char>::iterator cursor = text.end();

    for (int i = 0; i < n_cmd; i++)
    {
        char cmd;
        cin >> cmd;

        if (cmd == 'L')
        {
            if (cursor != text.begin())
                cursor--;
        }
        else if (cmd == 'D')
        {
            if (cursor != text.end())
                cursor++;
        }
        else if (cmd == 'P')
        {
            char op;
            cin >> op;
            text.insert(cursor, op);
        }
        else if (cmd == 'B')
        {
            if (cursor != text.begin())
            {
                cursor--;
                cursor = text.erase(cursor);
            }
        }
    }
    for (cursor = text.begin(); cursor != text.end(); cursor++)
        cout << *cursor;
    cout << "\n";
    return 0;
}