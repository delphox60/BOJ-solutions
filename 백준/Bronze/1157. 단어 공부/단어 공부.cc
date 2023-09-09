#include <iostream>
#include <string>

using namespace std;

int arr['z' + 1];
int offset = 'a' - 'A';

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    for (int i = 'a'; i <= 'z'; i++)
        arr[i] = 0;

    for (char c : s)
    {
        if (c < 'a')
        {
            c += offset;
        }
        arr[c]++;
    }

    char result = '?';
    int maxval = 0;

    for (int i = 'a'; i <= 'z'; i++)
    {
        if (arr[i] > maxval)
        {
            result = i - offset;
            maxval = arr[i];
        }

        else if (arr[i] == maxval)
        {
            result = '?';
        }
    }

    cout << result;
}