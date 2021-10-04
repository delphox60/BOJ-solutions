#include <cstring>
#include <iostream>

using namespace std;

int getGap(int x, int y)
{
    if (x > y)
        return x - y;
    else if (x < y)
        return y - x;
    else
        return 0;
}

int main()
{
    string str1, str2;
    cin >> str1 >> str2;

    int arr1[26], arr2[26];
    for (int i = 0; i < 26; i++)
    {
        arr1[i] = 0;
        arr2[i] = 0;
    }

    for (int i = 0; i < str1.length(); i++)
    {
        arr1[(int)str1[i] - 97]++;f
    }

    for (int i = 0; i < str2.length(); i++)
    {
        arr2[(int)str2[i] - 97]++;
    }

    int result = 0;
    for (int i = 0; i < 26; i++)
    {
        result += getGap(arr1[i], arr2[i]);
    }
    cout << result << '\n';
    return 0;
}