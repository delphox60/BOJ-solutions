#include <iostream>
#include <string>

using namespace std;

int arr[21];

void empty()
{
    for (int i = 0; i < 21; i++)
        arr[i] = 0;
}

void all()
{
    for (int i = 0; i < 21; i++)
        arr[i] = 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    empty();

    int m;
    cin >> m;

    while (m--)
    {
        string cmd;
        cin >> cmd;

        if (cmd == "all")
            all();

        else if (cmd == "empty")
            empty();

        else if (cmd == "add")
        {
            int x;
            cin >> x;
            if (arr[x] == 0)
            {
                arr[x]++;
            }
        }

        else if (cmd == "remove")
        {
            int x;
            cin >> x;
            if (arr[x] > 0)
            {
                arr[x] = 0;
            }
        }
        else if (cmd == "check")
        {
            int x;
            cin >> x;
            cout << arr[x] << '\n';
        }
        else if (cmd == "toggle")
        {
            int x;
            cin >> x;
            arr[x] = (arr[x] == 1) ? 0 : 1;
        }
    }
}
