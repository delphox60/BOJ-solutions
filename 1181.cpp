#include <iostream>
#include <cstring>
#include <algorithm>

int main()
{
    using namespace std;
    int n;
    cin >> n;
    string list[n];
    int maxlength = 0;
    int used_index_list[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
        if (maxlength < list[i].length())
            maxlength = list[i].length();
    }
    sort(list, list + n);
    for (int i = 1; i < maxlength + 1; i++)
    {
        for (int j = 0; j < n; j++)
            if (list[j].length() == i && list[j] != list[j - 1])
                cout << list[j] << endl;
    }
    return 0;
}