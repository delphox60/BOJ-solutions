#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        list<char> text;
        list<char>::iterator cursor;

        for (int i = 0; i < input.length(); i++)
        {
            if (input[i] == '<')
            {
                if (cursor != text.begin() && !text.empty())
                    cursor--;
            }
            else if (input[i] == '>')
            {
                if (cursor != text.end() && !text.empty())
                    cursor++;
            }
            else if (input[i] == '-')
            {
                if (cursor != text.begin() && !text.empty())
                {
                    cursor--;
                    cursor = text.erase(cursor);
                }
            }
            else
            {
                if (text.empty())
                {
                    text.push_back(input[i]);
                    cursor = text.end();
                }
                else
                    text.insert(cursor, input[i]);
            }
        }

        for (cursor = text.begin(); cursor != text.end(); cursor++)
            cout << *cursor;
        cout << "\n";
    }
    return 0;
}