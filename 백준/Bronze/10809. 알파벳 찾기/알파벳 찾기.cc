#include <iostream>
#include <cstring>

using namespace std;

int arr['z' - 'a' + 1];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string tar;
    cin >> tar;

    int len = tar.length();

    for (int i = 0; i <= 'z' - 'a'; i++)
        arr[i] = -1;

    for (int i = 0; i < len; i++)
    {
        if (arr[tar[i] - 'a'] < 0)
            arr[tar[i] - 'a'] = i;
    }

    for (int i : arr)
        cout << i << ' ';
}