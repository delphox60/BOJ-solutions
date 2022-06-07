#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str1, str2;
    int table[1000][1000];

    cin >> str1 >> str2;

    int l1 = str1.size();
    int l2 = str2.size();

    table[0][0] = str1[0] == str2[0] ? 1 : 0;

    for (int i = 1; i < l1; i++)
    {
        table[i][0] = str1[i] == str2[0] ? 1 : 0;
        table[i][0] = max(table[i][0], table[i - 1][0]);
    }

    for (int i = 1; i < l2; i++)
    {
        table[0][i] = str2[i] == str1[0] ? 1 : 0;
        table[0][i] = max(table[0][i], table[0][i - 1]);
    }

    for (int i = 1; i < l1; i++)
        for (int j = 1; j < l2; j++)
        {
            table[i][j] = max(table[i][j - 1], table[i - 1][j]);
            if (str1[i] == str2[j])
                table[i][j] = max(table[i][j], table[i - 1][j - 1] + 1);
        }

    cout << table[l1 - 1][l2 - 1] << endl;
}
